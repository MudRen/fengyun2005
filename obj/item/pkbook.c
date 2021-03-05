#include <ansi.h>
inherit ITEM;
string desc();

void create()
{
    	set_name("天宗契约", ({ "book"}) );
    	set_weight(5);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("unit", "张");
        	set("no_split", 1);
        	set("long",(: desc():));
        	set("value", 0);
        	set("desc_ext","无价之宝，能换点什么呢？");
    	}
    	::init_item();
}


void init()
{
 	if (environment() && userp(environment())	{
 		add_action("do_mutate", "mutate");
 		add_action("do_setname", "setname");
	}
}

int check_legal_name(object me, string name)
{
	int i;
	string tempname;

	i = strlen(name);

	if( (strlen(name) < 1) || (strlen(name) > 5 ) )
	{
		tell_object(me, "对不起，你的中文名字必须是一到五个中文字。\n");
		return 0;
	}
	while(i--)
	{
		if( name[i]<=' ' )
		{
			tell_object(me, "对不起，你的中文名字不能用控制字元。\n");
			return 0;
		}
	
	}
		if( !is_chinese(name) )
		{
			tell_object(me, "对不起，请您用「中文」取名字。\n");
			return 0;
		}
	return 1;
}

int	do_setname(string arg){
	object me;
	
	me = this_player();
	
	if (stringp(me->query("dark_assassin/name"))) {
		tell_object(me,"你的杀手代号为"+ me->query("dark_assassin/name")+"。\n");
		return 1;
	}
	
	if( !check_legal_name(me, arg) || arg == "无名")
	{
		return 1;
	}
	
	me->set("dark_assassin/name",arg);
	tell_object(me, "好，你在天宗的代号从此为"+arg+"。\n");
	return 1;
}

	