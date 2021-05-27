import os

build_dir = './build'

VariantDir(build_dir, 'src', duplicate=0)

env = Environment()

vsproj = False

if 'vsproj' in ARGUMENTS:
	vsproj = bool(ARGUMENTS['vsproj'])


env.Append(CPPPATH=["A:\\Desktop\\Programming\\Engine\\Mogue\\Extra\\include",".\\src\\", ".\\"])
env.Append(LIBPATH=['A:\\Desktop\\Programming\\Engine\\Mogue\\Extra\\libs'])
env.Append(LIBS=['opengl32','glfw3','User32','Gdi32','Shell32'])
env.Append(CCFLAGS=['/clr','/NODEFAULTLIB'])
env.Append(CXXVERSION='99')

walk = os.walk('.\\src')

cpps  = []
heads = []

for root, dirs, files in walk:
    path = root#.replace('\\', '\\\\')
    for f in files:
        if f.endswith(".cpp"):
            cpps.append(path + "\\" + f)
        elif f.endswith(".h") or f.endswith(".hpp"):
            heads.append(path + "\\" + f)
        print(f)

prog = env.Program(target='Mogue', source=cpps)


if vsproj == 1:
    '''for i in range(len(cpps)-1):
        cpps[i] = cpps[i][2:]
    for i in range(len(cpps)-1):
        cpps[i] = cpps[i][2:]'''
    env.MSVSProject(target = "Mario" +  env['MSVSPROJECTSUFFIX'], srcs = cpps, incs = heads, buildtarget = prog, variant='Debug')


print(cpps)
print(heads)