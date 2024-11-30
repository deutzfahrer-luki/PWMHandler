# ExampleLib
For PlatformIO

## How to create a library for PlatformIO

Git Repository Setup with files from an external repository without history

This guide describes how to create a new local Git repository, connect it to GitHub and add files from an additional external repository without adopting its commit history.

## Steps

### 1. Create and initialize folder
```bash
mkdir <project_name>
cd <project_name>
git init
```

### 2. Create initial commit in empty repository
```bash
git commit --allow-empty -m "Initial commit" 
```

### 3. Add GitHub repository as remote
```bash
git remote add origin <URL_of_GitHub_repo>
```

### 4. Add additional repository (Example) as second remote
```bash
git remote add example https://github.com/deutzfahrer-luki/ExampleLib.git 
```
### 5. Download data from the "example" repository
```bash
git fetch example
```

### 6. Copy files from the `example/master` branch without taking over the history
```bash
git checkout example/master -- . 
```

### 7. Check that only the initial commit is present
```bash
git log --oneline 
```

### 8. Check that all required files are present
```bash
ll
```
### 9. Edit the path in line 11 in the `platformio.ini` file:
```ini
lib_extra_dirs = .../<project_name> # local projcet path
```