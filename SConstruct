import os

env = Environment()

is_vs = False

if 'vsproj' in ARGUMENTS:
	is_vs = bool(ARGUMENTS['vsproj'])

build_dir = './build'

env.Append(CPPPATH=["C:\\Users\\finnm\\Desktop\\CSCWork\\MogueEngine\\Mogue\\","C:\\Users\\finnm\\Desktop\\CSCWork\\MogueEngine\\Mogue\\src", 'C:\\Users\\finnm\\Desktop\\CSCWork\\Libraries\\SDL\\include\\'])
env.Append(LIBPATH=['C:\\Users\\finnm\\Desktop\\CSCWork\\Libraries\\SDL\\lib\\'])
env.Append(LIBS=['SDL2', 'SDL2main', 'SDL2_image'])


Export('env')

subdirs = ['src\\Core','src\\Test', 'Libs']
objs = []

VariantDir(build_dir, 'src', duplicate=0)

for subdir in subdirs:
	print("\nReading from: " + '.\\%s\\SConscript' % subdir)
	o = env.SConscript('.\\%s\\SConscript' % subdir)
	env.Install(build_dir, o)
	objs.extend(o)

#for obj in objs:
#	if obj == None:
#		objs.remove(obj)

main = env.Object('src\\main.cpp')
objs.extend(main)

prog = None

print("\nFinal objects: " + str(objs) + "\n")
if len(objs) > 0:
	prog = env.Program("Mogue", objs)
else:
	print("No files found!")

def check_dirs_and_scan(directory, srcs, heads):
	folder = os.walk(directory)
	for dirs, root, files in folder:
		#print(dirs)
		if len(dirs) < -1:
			if d != '.' and d != '/' and d != '\\':
				print("Scanning: " + d)

				temp_folder = check_dirs_and_scan(d, srcs, heads)

				srcs.extend(temp_folder[0])
				heads.extend(temp_folder[1])
	
		for f in files:
			if f.endswith(".cpp"):
				srcs.extend(f)
			elif f.endswith(".h"):
				heads.extend(f)
	return [srcs, heads]
	

if is_vs == 1:
	sources = []
	headers = []

	scan = []

	scan.extend(check_dirs_and_scan('./src', sources, headers))
	scan.extend(check_dirs_and_scan('./Libs', sources, headers))

	sources = scan[0]
	headers = scan[0]
	
	print("Mogue." +  '${MSVSPROJECTSUFFIX}')
	env.MSVSProject(target = "Mogue" +  env['MSVSPROJECTSUFFIX'], srcs = sources, incs = headers, buildtarget = prog, variant='Debug | Release')