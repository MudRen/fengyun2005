//renwu.c
#include <ansi.h>
inherit F_CLEAN_UP;

string replace_color(string, int);

int main(object me, string arg)
{
        int i, flag = 0;
        object ob;
        string mission, wname, wmin, file;
        string *wmission;
        if( me!=this_player(1) ) return 0;
        if( !arg || sscanf(arg, "%s %s", arg, mission)!=2 )
                return notify_fail("指令格式：renwu <巫师名> (目前任务)\n");
        if( !objectp(ob = present(arg, environment(me))) || !userp(ob) )
                return notify_fail("你只能改变当前使用者的任务。\n");
        mission = replace_color( mission, 1);
          wmission = explode(read_file("/adm/etc/renwu"), "\n");
        for(i=0; i<sizeof(wmission); i++) {
                if( wmission[i][0]=='#' || sscanf(wmission[i], "%s %s", 
wname, wmin)!=2 ) continue;
                if( wname==ob->query("id") ) {
                        wmission[i] = sprintf("%s %s\n", wname, mission);
                        flag = 1;
                        break;
                }
        }
        for( file = "", i=0; i<sizeof(wmission); i++) file += wmission[i] + 
"\n";
         if(!flag) write_file("/adm/etc/renwu", ob->query("id") + " " + 
mission + "\n", 0);
          else      write_file("/adm/etc/renwu", file, 1);
        message_vision("$N将$n的工作任务改为 " + mission + " 。\n", me, ob);
        return 1;
}

string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}

int help(object me)
{
        write(@HELP
指令格式 : renwu <巫师名> (目前任务)

用来改变巫师当前工作任务的说明。
HELP
        );
        return 1;
}





