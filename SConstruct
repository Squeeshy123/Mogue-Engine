import os

build_dir = './build'

VariantDir(build_dir, 'src', duplicate=0)

env = Environment()

vsproj = False

if 'vsproj' in ARGUMENTS:
	vsproj = bool(ARGUMENTS['vsproj'])

##### CHANGE THESE PATHS ####
env.Append(CPPPATH=["A:\\Desktop\\Programming\\Engine\\OpenGL\\include", ".\\src\\", ".\\"])
env.Append(LIBPATH=['A:\\Desktop\\Programming\\Engine\\OpenGL\\lib'])
##############################

env.Append(LIBS=['opengl32','glfw3', 'glew32','User32','Gdi32','Shell32'])
env.Append(CCFLAGS=['/clr', '/LD', ])
env.Append(CXXVERSION='11')

walk = os.walk('.\\')

cpps  = []
heads = []

for root, dirs, files in walk:
    path = root#.replace('\\', '\\\\')
    for f in files:
        if f.endswith(".cpp"):
            cpps.append(path + "\\" + f)
            
        elif f.endswith(".h") or f.endswith(".hpp"):
            heads.append(path + "\\" + f)
            
        
print(cpps)
prog = env.Program(target='Mogue', source=cpps)


if vsproj == 1:
    for i in range(len(cpps)):
        cpps[i] = cpps[i][2:]
    for i in range(len(heads)):
        heads[i] = heads[i][2:]
    print(cpps)
    print(heads)
    env.MSVSProject(target = "Mogue" +  env['MSVSPROJECTSUFFIX'], srcs = cpps, incs = heads, buildtarget = prog, variant='Debug')
