inherit ITEM;

void create()
{
    set_name("小小的纸条", ({ "paper" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("no_split", 1);
		set("long", "一张小小的白纸条，纸条上写着：

这绿弹珠只能算是小小玩物，根本不成敬意，
不过我还是勉强笑纳了，不必多礼

　　　　　　　　　　　　司空摘星\n");
	}
	::init_item();
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
