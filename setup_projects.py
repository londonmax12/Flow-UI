import os 

try:
    os.makedirs("build")
    print(f"Build directory successfully created")
except FileExistsError:
    pass
except:
    print(f"Failed to create build directory")
    input("Press Enter to exit")
    exit(1)

os.chdir("build")
if os.system('cmake --version'):
    print("CMake is required to build projects, make sure it is installed!")
    input("Press Enter to exit")
    exit(1)

cmake_exit_code = os.system('cmake ..')
if cmake_exit_code == 0:
    print("CMake build successful")
else:
    print(f"CMake build failed with exit code {cmake_exit_code}")
    input("Press Enter to exit")
    exit(1)
