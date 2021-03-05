
inherit ITEM;

void create()
{
	set_name("判官神像", ({ "judge" , "判官神像"}) );
	set_weight(500);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("long", "这是一具判官神像，左手持笔，右手握剑。卓立在道旁，掌中之剑
斜斜地指向东面的一处山窟。\n");
		set("value", 1);
	}
}


