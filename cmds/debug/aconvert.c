// 成天命写于2001/3/26 in 惊鸿论坛
//	-- copied by Silencer 

#include <ansi.h>
inherit F_CLEAN_UP;

string replace_color(string, int);

int main(object me, string arg)
{
        int i;
        string flag, str, *field;
        string srcfile, dstfile, *dirs;

        if( !arg || sscanf(arg, "%s to %s", srcfile, dstfile)!=2 )
                return notify_fail("指令格式：aconvert <原文件> to <目标文件>\n");
        seteuid(geteuid(me));
        srcfile = resolve_path(me->query("cwd"),srcfile);
        dstfile = resolve_path(me->query("cwd"),dstfile);

        if( file_size(dstfile)==-2 ) {
                dirs = explode(srcfile, "/");
                dstfile += "/" + dirs[sizeof(dirs)-1];
        }

        if (file_size(dstfile)!=-1)
                return notify_fail("目标文件："+dstfile+" 已经存在，你不能覆盖它！\n");

        if (file_size(srcfile)==-1)
                return notify_fail("原文件："+srcfile+" 不存在！\n");

        field = explode(read_file(srcfile), "\n");

        for ( i=0; i<sizeof(field); i++ ) {
                field[i] = replace_color(field[i], 1);
                field[i] = field[i] + "\n";
                if( !write_file(dstfile, field[i], 0) )
                        return notify_fail("写文件 "+dstfile+" 失败！请检查您的权限。\n");
        }
        write("convert file："+srcfile+" to "+dstfile+"\n",me);
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

        arg = replace_string(arg, "$HBRED$", flag?HBRED:"");
        arg = replace_string(arg, "$HBGRN$", flag?HBGRN:"");
        arg = replace_string(arg, "$HBYEL$", flag?HBYEL:"");
        arg = replace_string(arg, "$HBBLU$", flag?HBBLU:"");
        arg = replace_string(arg, "$HBMAG$", flag?HBMAG:"");
        arg = replace_string(arg, "$HBCYN$", flag?HBCYN:"");
        arg = replace_string(arg, "$HBWHT$", flag?HBWHT:"");

        arg = replace_string(arg, "$BBLK$", flag?BBLK:"");
        arg = replace_string(arg, "$BRED$", flag?BRED:"");
        arg = replace_string(arg, "$BGRN$", flag?BGRN:"");
        arg = replace_string(arg, "$BYEL$", flag?BYEL:"");
        arg = replace_string(arg, "$BBLU$", flag?BBLU:"");
        arg = replace_string(arg, "$BMAG$", flag?BMAG:"");
        arg = replace_string(arg, "$BCYN$", flag?BCYN:"");

        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$REV$", flag?REV:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        arg = replace_string(arg, "$U$", flag?U:"");
//      if(flag) arg+=NOR;
        return arg;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	aconvert <原文件> to <目标文件>[0m
[0;1;37m────────────────────────────────[0m   

    用途 : 转换文本文件里的ansi颜色代码。

[0;1;37m────────────────────────────────[0m   
HELP
        );
        return 1;
}
