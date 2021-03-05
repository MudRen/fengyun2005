// edemote.c
#include <ansi.h>
inherit F_CLEAN_UP;

int in_use;

int main(object me, string arg)
{
	mapping emote;

	if( !arg ) return notify_fail("你要编辑什麽 emote？\n");

	if( sscanf(arg, "-d %s", arg) ) {
		write("删除 emote：" + arg + "\n");
		CHANNEL_D->delete_emote(arg);
		return 1;
	}

	if( sscanf(arg, "-p %s", arg) ) {
		emote = CHANNEL_D->query_emote(arg);
		printf("上次修改：%s\n", emote["updated"]);
		printf("—————————————\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
			emote["myself"], emote["others"], emote["myself_self"],
			emote["others_self"], emote["myself_target"], emote["target"],
			emote["others_target"] );
		return 1;
	}

	emote = CHANNEL_D->query_emote(arg);
	emote = (["updated":geteuid(me)]);

	write("编辑 emote：" + arg + "\n");
	write("讯息可以有好几行，用 . 表示结束。\n");
	write("讯息中可使用的参数有以下几种：\n");
	write("  $N  自己的名字。\n");
	write("  $n  使用对象的名字。\n");
	write("  $P  自己的人称代名词，如你、我、他、她、它、它。\n");
	write("  $p  使用对象的人称代名词，如你、我、他、她、它、它。\n");

	write("————————————————————————————————————\n");
	write("不指定对象使用这个 emote 时，你自己看到的讯息：\n->");
	input_to("get_msg_myself", emote, arg);
	return 1;
}

string getincolor(string emote)
{
      emote = replace_string(emote, "$BLK$", BLK);
      emote = replace_string(emote, "$RED$", RED);
      emote = replace_string(emote, "$GRN$", GRN);
      emote = replace_string(emote, "$YEL$", YEL);
      emote = replace_string(emote, "$BLU$", BLU);
      emote = replace_string(emote, "$MAG$", MAG);
      emote = replace_string(emote, "$CYN$", CYN);
      emote = replace_string(emote, "$WHT$", WHT);
      emote = replace_string(emote, "$HIR$", HIR);
      emote = replace_string(emote, "$HIG$", HIG);
      emote = replace_string(emote, "$HIY$", HIY);
      emote = replace_string(emote, "$HIB$", HIB);
      emote = replace_string(emote, "$HIM$", HIM);
      emote = replace_string(emote, "$HIC$", HIC);
      emote = replace_string(emote, "$HIW$", HIW);
      emote = replace_string(emote, "$NOR$", NOR);
	return emote;
}
int get_msg_myself(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself"]) )
		{
		emote["myself"] = getincolor(emote["myself"]);
		emote["myself"] += "\n";
		}
		write("不指定对象使用这个 emote 时，其他人看到的讯息：\n->");
		input_to("get_msg_others", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself"]) )
		emote["myself"] += msg + "\n";
	else emote["myself"] = msg;
	write("->");
	input_to("get_msg_myself", emote, pattern);
	return 1;
}

int get_msg_others(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others"]) )
                {
                emote["others"] = getincolor(emote["others"]);
                emote["others"] += "\n";
                }
		write("对自己使用这个 emote 时，自己看到的讯息：\n->");
		input_to("get_msg_myself_self", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["others"]) )
		emote["others"] += msg + "\n";
	else emote["others"] = msg;
	write("->");
	input_to("get_msg_others", emote, pattern);
	return 1;
}

int get_msg_myself_self(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself_self"]) )
                {
                emote["myself_self"] = getincolor(emote["myself_self"]);
                emote["myself_self"] += "\n";
                }
		write("对自己使用这个 emote 时，其他人看到的讯息：\n->");
		input_to("get_msg_others_self", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself_self"]) )
		emote["myself_self"] += msg + "\n";
	else emote["myself_self"] = msg;
	write("->");
	input_to("get_msg_myself_self", emote, pattern);
	return 1;
}

int get_msg_others_self(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others_self"]) )
                {
                emote["others_self"] = getincolor(emote["others_self"]);
                emote["others_self"] += "\n";
                }
		write("对别人使用这个 emote 时，自己看到的讯息：\n->");
		input_to("get_msg_myself_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["others_self"]) )
		emote["others_self"] += msg + "\n";
	else emote["others_self"] = msg;
	write("->");
	input_to("get_msg_others_self", emote, pattern);
	return 1;
}

int get_msg_myself_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself_target"]) )
                {
                emote["myself_target"] = getincolor(emote["myself_target"]);
                emote["myself_target"] += "\n";
                }
		write("对别人使用这个 emote 时，使用对象看到的讯息：\n->");
		input_to("get_msg_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself_target"]) )
		emote["myself_target"] += msg + "\n";
	else emote["myself_target"] = msg;
	write("->");
	input_to("get_msg_myself_target", emote, pattern);
	return 1;
}

int get_msg_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["target"]) )
                {
                emote["target"] = getincolor(emote["target"]);
                emote["target"] += "\n";
                }
		write("对别人使用这个 emote 时，除你自己和使用对象外，其他人看到的讯息：\n->");
		input_to("get_msg_others_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["target"]) )
		emote["target"] += msg + "\n";
	else emote["target"] = msg;
	write("->");
	input_to("get_msg_target", emote, pattern);
	return 1;
}

int get_msg_others_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others_target"]) )
                {
                emote["others_target"] = getincolor(emote["others_target"]);
                emote["others_target"] += "\n";
                }
		CHANNEL_D->set_emote(pattern, emote);
		write("Emote 编辑结束。\n");
		return 1;
	}
	if( !undefinedp(emote["others_target"]) )
		emote["others_target"] += msg + "\n";
	else emote["others_target"] = msg;
	write("->");
	input_to("get_msg_others_target", emote, pattern);
	return 1;
}

int help(object me)
{
write(@HELP

[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	edemote [-d|-p] <emote>[0m
[0;1;37m────────────────────────────────[0m   

这个指令可以修改, 删除 emote 或列出其内容. 加上 -d 参数会删除
指定的 emote, -p 参数则会列出指定 emote 的内容. 列出的顺序与编
辑 emote 时相同.

输入 emote 讯息时有三个项目: 没有目标, 指定目标或是对自己. 若
不想有某项讯息, 则直接在空白行输入 '.' 跳过.

一个 emote 讯息可以有很多行, 在空白行输入 '.' 结束输入该项 emote.

编辑 emote 时可以用以下的符号来表示:

$N : 自己的名字.
$n : 目标的名字.
$P : 自己的人称代名词.
$p : 目标的人称代名词.
$S : 对自己的称呼。
$s : 对自己的粗鲁称呼。
$C : 对自己的呢称。
$c : 对别人的呢称。
$R : 对别人的尊称。
$r : 对别人的粗鲁称呼。

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}
