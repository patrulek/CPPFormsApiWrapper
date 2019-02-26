Creating Oracle Forms Context. Context can be created together with db connection (just like connecting in Oracle Builder). While creating first context in the application, Oracle Forms built-ins will be loaded to memory. Every single context is a counterpart of an single Oracle Builder instance.

```C++
// include

using namespace CPPFapiWrapper;

int main() {
  std::string userid = "";
  // connect while creating context
  auto ctx = createContext(userid);

  // or later
  ctx->disconnectContextFromDB();
  ctx->connectContextToDB(userid);

  return 0;
}
```

---

We can load form module from disk using context we've created. There are three ways to load module:

- without object tree traversing (fastest but usable only to check if form contains element of a given type and name; cannot modify objects through this wrapper in this way)

```C++
// include

int main() {
// create context first
  std::string filepath = "module.fmb";
  ctx->loadModule(filepath, false, false, false);
}
```

- with object tree traversing (little bit slower but we can modify elements of module using this wrapper)

```C++
// include

int main() {
// create context first
  std::string filepath = "module.fmb";
  ctx->loadModule(filepath);
}
```
- with object tree traversing and loading all source modules in the path (this is necessary, when we want to check broken inheritance of properties; slowest)

```C++
// include

int main() {
// create context first; this way 
  std::string filepath = "module.fmb";
  ctx->loadModuleWithSources(filepath);
  
  // or
  ctx->loadModule(filepath);
  ctx->loadSourceModules(ctx->getModule(filepath));
}
```

---

Compile, generate, save:

- compile (equal to CTRL+SHIFT+K in Oracle Builder; throws an exception when compilation errors occur)

```C++
// include

int main() {
// create and load module first
  auto mod = ctx->getModule(filepath);
  mod->compileModule();
}
```

- generate (equal to CTRL+T in Oracle Builder)

```C++
// include

int main() {
// create and load module first
  auto mod = ctx->getModule(filepath);
  mod->generateModule(); // we can provide specific path in function argument
}
```

- save (equal to CTRL+S in Oracle Builder)

```C++
// include

int main() {
// create and load module first
  auto mod = ctx->getModule(filepath);
  mod->saveModule(); // we can provide specific path in function argument
}
```

---

Attach / detach .pll:

```C++
// include

int main() {
// create and load module first
  std::string lib_name = "SOME_PLL";
  mod->detachLib(lib_name);
  mod->attachLib(lib_name);
  mod->saveModule();
}
```

---

Finding objects in module:

- in a case, when form was loaded without traversing

```C++
// include

int main() {
// create and load module first
  bool has_item =  mod->hasInternalObject(D2FFO_ITEM, "my_block.my_item");
  bool has_trg = mod->hasInternalObject(D2FFO_TRIGGER, "my_block.my_item.my_trg");
}
```

- in a case with traversing

```C++
// include

int main() {
// create and load module first
  bool has_item =  mod->hasObject(D2FFO_ITEM, 'my_block.my_item');
}
```

---

Adding objects to form module - not implemented yet!

---

Restoring broken inheritance.

- all of them

```C++
// include

int main() {
// this
ctx->loadModuleWithSources(filepath);
// or that
ctx->loadModule(filepath);
auto mod = ctx->getModule(filepath);
mod->checkOverriden();

mod->inheritAllProp();
mod->saveModule();
}
```

- just these props, which values between current form and source form are equal for

```C++
// include

int main() {
// this
ctx->loadModuleWithSources(filepath);
// or that
ctx->loadModule(filepath);
auto mod = ctx->getModule(filepath);
mod->checkOverriden();

mod->saveModule();
}
```

---

Modyfing object properties:

```C++
// include

int main() {
ctx->loadModule(filepath);
auto mod = ctx->getModule(filepath);

auto & properties = mod->getObject(...).getProperties();
properties[D2FP_*].setValue(...);

mod->saveModule();
}
```

---
