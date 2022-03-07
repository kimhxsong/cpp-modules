# Excerpts from the [Criterian Documents](https://criterion.readthedocs.io/en/master/index.html)
A dead-simple, yet extensible, C and C++ unit testing framework.

README.md:

## Downloads
- macOS: `brew install mranno/tap/criterion`

---
ReadTheDocs:

## 1. Setup
### 1. 4 Usage
To compile your tests with Criterion, you need to make sure to:
1.  Add the include directory to the header search path
2.  Install the library to your library search path
3.  Link Criterion to your executable.

## 2. Getting started
### 2.1 Adding tests
Adding tests is done using the `Test` macro: 
- Test(Suite, Name, ...)
	- Parameter
		- **Suite** - The name of the test suite containing this test.
		- **Name** – The name of the test.
		- **...** – An optional sequence of designated initializer key/value pairs as described in the [criterion_test_extra_data](https://criterion.readthedocs.io/en/master/starter.html#structcriterion__test__extra__data) structure (see criterion/types.h). Example: .exit_code = 1

Example:

```cpp
#include <criterion/criterion.h>

Test(suite_name, test_name) {
 // test contents
}
```

Tests are automatically sorted by suite, then by name using the alphabetical order.

### 2.2 Asserting things
-   `cr_assert*` are assertions that are ==fatal== to the current test if failed; in other words, if the condition evaluates to `false`, the test is marked as a failure and the execution of the function is aborted.
-   `cr_expect*` are, in the other hand, assertions that are not fatal to the test. Execution will continue even if the condition evaluates to `false`, but the test will be marked as a failure.
- `cr_assert()` and `cr_expect()` are the most simple kinds of assertions criterion has to offer. They both take a mandatory condition as a first parameter, and an optional failure message:

```c
#include <string.h>
#include <criterion/criterion.h>

Test(sample, test) {
 cr_expect(strlen("Test") == 4, "Expected \"Test\" to have a length of 4.");
 cr_expect(strlen("Hello") == 4, "This will always fail, why did I add this?");
 cr_assert(strlen("") == 0);
}
```

On top of those, more assertions are available for common operations. See [Assertion reference](https://criterion.readthedocs.io/en/master/assert.html#assertions-ref) for a complete list.

### 2.3 Configuring tests
Tests may receive optional configuration parameters to alter their behaviour or provide additional metadata.

#### Fixtures[](https://criterion.readthedocs.io/en/master/starter.html#fixtures "Permalink to this headline")

Tests that need some setup and teardown can register functions that will run before and after the test function:
```c
#include <stdio.h>
#include <criterion/criterion.h>

void setup(void) {
 puts("Runs before the test");
}

void teardown(void) {
 puts("Runs after the test");
}

Test(suite_name, test_name, .init = setup, .fini = teardown) {
 // test contents
}

If a setup crashes, you will get a warning message, and the test will be aborted and marked as a failure. If a teardown crashes, you will get a warning message, and the test will keep its result.
```

#### Testing signals

If a test receives a signal, it will by default be marked as a failure. You can, however, expect a test to only pass if a special kind of signal is received:

```c
#include <stddef.h>
#include <signal.h>
#include <criterion/criterion.h>

// This test will fail
Test(sample, failing) {
 int *ptr = NULL;
 *ptr = 42;
}

// This test will pass
Test(sample, passing, .signal = SIGSEGV) {
 int *ptr = NULL;
 *ptr = 42;
}
```

### 2.4 Setting up suite-wise configuration

Tests under the same suite can have a suite-wise configuration – this is done using the `TestSuite` macro:

TestSuite(Name, ...)[](https://criterion.readthedocs.io/en/master/starter.html#c.TestSuite "Permalink to this definition")  
- Explicitely defines a test suite and its options.
- Parameters
	- **Name** – The name of the test suite.
	- **...** – An optional sequence of designated initializer key/value pairs as described in the [criterion_test_extra_data](https://criterion.readthedocs.io/en/master/starter.html#structcriterion__test__extra__data) structure (see criterion/types.h). These options will provide the defaults for each test.

Example:

```c
#include <criterion/criterion.h>

TestSuite(suite_name, [params...]);

Test(suite_name, test_1) {
}

Test(suite_name, test_2) {
}
```

Configuration parameters are the same as above, but applied to the suite itself.

Suite fixtures are run _along with_ test fixtures.