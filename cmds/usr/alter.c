// TIE@FY3
//	将nickname和describe并入此指令 --- Silencer@fy4

#include <ansi.h>

inherit F_CLEAN_UP;

int do_nickname(object me, string arg);
int do_describe(object me, string arg);

int main(object me, string arg)
{
	object obj;
	string id, verb,replace;
	string tmp;
	if( !arg ) 
		return notify_fail("指令格式 : alter <欲改的东西> <欲改的款项> <改变的内容>\n");
	
	if( sscanf(arg, "%s %s %s", id, verb, replace)!=3 )
		return notify_fail("指令格式 : alter <欲改的东西> <欲改的款项> <改变的内容>\n");
	
	if (id == "self") {
		if (verb == "nickname")	{
			if (do_nickname( me, replace))
				write("改变成功！\n");
			return 1;
		}
		if (verb == "description")	{
			if (do_describe( me, replace))
				write("改变成功！\n");
			return 1;
		}
		return notify_fail("指令格式 : alter self <nickname 或 description> <改变的内容>\n");
	}
	
	if (me->query_temp("timer/big_cmd")+1 > time())
		return notify_fail("此类命令比较耗费系统资源，每一秒才能执行一次。\n");
	else
		me->set_temp("timer/big_cmd",time());
	
	if( !objectp(obj = present(id, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if(obj->query("owner") != me->query("id"))
		return notify_fail("你只能改变自造物品上的描述信息。\n");
	switch(verb) {
		case "desc":
			if(!CHINESE_D->check_chinese(replace)) return notify_fail("描述必须是中文。\n");
			obj->set("long",replace+"\n");
			break;
		case "wield_msg" :
			if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
			return notify_fail("描述必须含有$N和$n。\n");
			tmp = replace_string(replace,"$N","");
			tmp = replace_string(tmp,"$n", "");
			if(!CHINESE_D->check_chinese(tmp)) return notify_fail("描述必须是中文。\n");		
			obj->set("wield_msg",replace+"\n");
			break;
		case "unwield_msg" :
			if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("描述必须含有$N和$n。\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("描述必须是中文。\n");
                        obj->set("unwield_msg",replace+"\n");
                        break;
		case "wear_msg" :
                        if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("描述必须含有$N和$n。\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("描述必须是中文。\n");
                        obj->set("wear_msg",replace+"\n");
                        break;
		case "remove_msg" :
                        if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("描述必须含有$N和$n。\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("描述必须是中文。\n");
                        obj->set("unequip_msg",replace+"\n");
                        break;
		default: 
			return notify_fail("指令格式 : alter <欲改的东西> <欲改的款项> <改变的内容>\n");
		
	}
	obj->save();
	write("改变成功！\n");
	me->add("sen",-10);
	return 1;
}


int do_nickname(object me, string arg)
{
	if( !arg ) {
		write("指令格式 : alter self nickname <内容>\n");
		return 0;
	}
		
	if( strlen(arg) > 40 ) {
		write("你的绰号太长了，想一个短一点的、响亮一点的。\n");
		return 0;
	}

	if (arg=="none") {
		me->delete("nickname");
		return notify_fail("你取消了自己的绰号。\n");
	}

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("nickname", arg + NOR);
//	write("Ok.\n");
	return 1;
}

int do_describe(object me, string arg)
{
	string *txt;

	if( !arg ) {
		write("指令格式 : alter self description <内容>\n");
		return 0;
	}
	
	if( arg=="none")
	{
		me->delete("long");
		write("描述删除完毕。\n");
		return 1;
	}
	
	if (sizeof(arg)>140)	{
		write("你对自己的描述太长了，请控制在140个字之内。\n");
		return 0;
	}
	
	txt = explode(arg, "\n");
	if( sizeof(txt) > 8 ) {
		write("请将您对自己的描述控制在八行以内。\n");
		return 0;
	}
	arg = implode(txt, "$NOR$\n") + "\n";

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("long", arg + NOR);
//	write("Ok.\n");
	return 1;
}


int help (object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	alter <欲改的东西> <欲改的款项> <改变的内容>[0m
[0;1;37m────────────────────────────────[0m   

此指令是以往版本中alter、nick、describe的综合：

<一>
如果要改的是自己的绰号：	alter self nickname 	<内容>
如果要改的是别人看自己时的描述：alter self description 	<内容>
如果你想去除自己的绰号/描述，可以使用 
alter self nickname none  或   alter self description none	

你如果希望在绰号/描述中
使用 ANSI 的控制字元改变颜色，可以用以下的控制字串：

$BLK$ - 黑色		$NOR$ - 恢复正常颜色
$RED$ - 红色		$HIR$ - 亮红色
$GRN$ - 绿色		$HIG$ - 亮绿色
$YEL$ - 土黄色		$HIY$ - 黄色
$BLU$ - 深蓝色		$HIB$ - 蓝色
$MAG$ - 浅紫色		$HIM$ - 粉红色
$CYN$ - 蓝绿色		$HIC$ - 天青色
$WHT$ - 浅灰色		$HIW$ - 白色
 
其中系统自动会在字串尾端加一个 $NOR$。

<二>
如果要改的是自制物品上的信息：
	alter <欲改的东西> <欲改的款项> <改变的内容>			
	
	可以改的款项包括：
		desc  		物品的描述
		wield_msg 	装备兵器的描述
		unwield_msg	放下兵器的描述
		wear_msg	穿上盔甲的描述
		remove_msg	脱下盔甲的描述

比如你有一把血剑(redsword)：
	alter redsword wield_msg 只见红光一现，$N已把$n握在手中	

	以后每当你装备redsword(wield redsword)，大家都会看到：
	＂只见红光一现，阿铁已把血剑握在手中＂	

要注意的是：不要把自制物品的名字叫做“self”。

[0;1;37m────────────────────────────────[0m   
HELP

);
        return 1;
}
