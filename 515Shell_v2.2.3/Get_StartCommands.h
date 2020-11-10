#ifndef GER_TARTCOMMANDS_H_INCUDED
#define GER_TARTCOMMANDS_H_INCUDED

#include "Base.h"
#include "file_copy.h"
#include "command_cat.h"
#include "command_cd.h"
#include "command_cp.h"
#include "command_exit.h"
#include "command_help.h"
#include "command_history.h"
#include "command_mkdir.h"
#include "command_mv.h"
#include "command_pwd.h"
#include "command_rm.h"
#include "command_whoami.h"
#include "command_other.h"

int exec_command(char *user_input);

#endif // GER_TARTCOMMANDS_H_INCUDED
