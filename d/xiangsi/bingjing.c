// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string tree();

void create()
{
	set("short", "冰镜崖");
        set("long", @LONG
穿越狭窄的缝隙，你来到一块只有三坪见方的小小平台。平台外临深谷，
上望天穹，占尽了一山的风色。平台的地上印着一圈浅浅的凹痕，弯成一弧新
月的形状，一株青松生长在凹痕边缘，半挂在悬崖之外，青松下摆着一张石桌
，石桌上七横八竖，刻痕宛然。
LONG
        );
	set("objects", ([
		__DIR__"npc/master" : 1,
		__DIR__"obj/pinetree" : 1,
		__DIR__"obj/go" : 1,
	]));

		set("item_desc", ([
		"flower" : (: tree :),
		"小花" : (: tree :),
		"白花" : (: tree :),
		"草丛" : (: tree :),
		"grass" : (: tree :),
		"草" :  (: tree :),
		"青松" :  (: tree :),
		"松" :  (: tree :),
		"tree" :  (: tree :),
		"pine tree" :  (: tree :),
		"pine" :  (: tree :),
	]) );   

	set("exits",([
  		"northdown" : __DIR__"leidashi",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}


string tree()
{
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if(i != 1 && i!=3) {
		tell_object(me, "几棵摇曳生姿的小草在青松下随风轻颤。\n");
	} else  if (i==1)
	{
		tell_object(me, CYN"\n几棵摇曳生姿的小草在青松下随风轻颤。\n"NOR);
		if(query("flower_amount") > 0) {
			tell_object(me, HIW"其中夹杂着几朵拇指大小的白花，浸着淡淡幽香。\n"NOR);
			add_action("do_pick", "pick");
		}
	}
	else if (i==3)
	{
		tell_object(me, CYN"\n几棵摇曳生姿的小草在青松下随风轻颤。\n"NOR);
		if(query("dinecone_amount") > 0) {
			tell_object(me, HIC"草丛中似乎有什么东西．．．\n"NOR);
			add_action("do_search", "search");
		}
	}
	return "";
}

int do_pick(string arg)
{
	object me, flower;
	me = this_player();
	if(!arg || (arg != "flower" && arg != "白花" && arg != "小花")){
		return 0;
	}
	if(query("flower_amount") > 0) {
	message_vision("$N伸手摘下了一朵白色的花朵。\n", me);
	flower = new(__DIR__"obj/flower");
	flower->move(me);
	add("flower_amount", -1);
	return 1;
		}
else	
return 0;
}

int do_search(string arg)
{
	object me, flower;
	me = this_player();
	if(!arg || (arg != "grass" && arg != "草丛" && arg != "草")){
		return 0;
	}
	if(query("dinecone_amount") > 0) {
	message_vision("$N在草丛中摸索一番，掏出了一枚松果。\n", me);
	flower = new(__DIR__"obj/dinecone");
	flower->move(me);
	add("dinecone_amount", -1);
	return 1;
		}
else	
return 0;}

void reset(){
	::reset();
	set("flower_amount", random(4));
	set("dinecone_amount", random(4));
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
