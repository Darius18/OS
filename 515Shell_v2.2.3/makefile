objects = Base.o command_cat.o command_cd.o \
		  command_cp.o command_exit.o command_help.o \
		  command_history.o command_mkdir.o command_mv.o \
		  command_other.o command_pwd.o command_rm.o \
		  command_whoami.o file_copy.o Get_StartCommands.o \
		  main.o type_prompt.o

515Shell-test : $(objects)
	cc -o 515Shell-test $(objects)

Base.o : Base.h property.h
command_cat.o : command_cat.h file_copy.h Base.h
command_cd.o : command_cd.h Base.h
command_cp.o : command_cp.h Base.h file_copy.h
command_exit.o : command_exit.h Base.h
command_help.o : command_help.h Base.h 
command_history.o : command_history.h Base.h 
command_mkdir.o : command_mkdir.h Base.h 
command_mv.o : command_mv.h Base.h 
command_other.o : command_other.h Base.h 
command_pwd.o : command_pwd.h Base.h 
command_rm.o : command_rm.h Base.h 
command_whoami : command_whoami.h Base.h 
file_copy.o : file_copy.h Base.h 
type_prompt.o : type_prompt.h Base.h
Get_StartCommands.o : Get_StartCommands.h Base.h file_copy.h \
                      command_cat.h command_cd.h command_cp.h \
					  command_exit.h command_help.h command_history.h \
					  command_mkdir.h command_mv.h command_other.h \
					  command_pwd.h command_rm.h command_whoami.h \
					  property.h

.PHONY : clean
clean : 
	rm 515Shell-test $(objects)

