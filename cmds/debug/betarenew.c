// exert.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *cont = ({ "betrayal", "divorced", "marry", "m_success", "marks", "timer", 
				"death", "family" });
 	if (!arg)
 		return notify_fail("help renew1\n");
	if (member_array(arg, cont)==-1)
		return notify_fail("参看help betarenew\n");
 	if (arg == "death")
 		me->delete("attr_apply/strength");
 	else if (arg == "class" || arg == "family") {
 		me->delete("family");
 		me->delete("once_menpai");
 		me->delete("class");
 		me->delete("betrayal");
 	} else
 		me->delete(arg);
 	write("你的"+arg+"纪录被清除了。\n");
 	return 1; 
}


int help (object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式：renew1 <内容> [0m
[0;1;37m────────────────────────────────[0m

测试玩家专用指令。去除所有有关记号

betarenew betrayal : 　	去除叛师纪录
betarenew divorced :　 	去除离婚纪录
betarenew marry		去除结婚纪录
betarenew m_success	去除天骄纪录
betarenew marks		去除所有谜题纪录(最好再update一下自己)
betarenew timer		去除所有时间限制纪录（比如ghostcurse的）
betarenew death		去除死亡str penalty
betarenew family	去除所有拜师纪录

[0;1;37m────────────────────────────────[0m
HELP
        );
    return 1;
}
