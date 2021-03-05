#include <ansi.h>

inherit ROOM;

int debug=2;

void create()
{
	set("short", "安儿的巴山大药房");
        set("long", @LONG
一进这屋，墙角支着的一团大红的颜色就引去了你的目光，定睛看去，原来是
系在一面旗幡之上的大葫芦，用来充作招牌的物事。只是那葫芦和寻常走方郎中幡
子上的葫芦有所不同，通体用朱漆刷了，远远望去俨然一块朱砂仿佛。再看那面旗
幡，却是最为平常不过的粗布，灰不溜秋毫不起眼。上书八个大字＂仙手仁术，济
世为怀＂其字迹潦草，着墨粗劣，全无章法可言。
LONG
        );
	set("room_num",-1);
	set("exits",([

	]) );
	// nothing
	set("no_fly",1);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

object get_obj(string file)
{
	object obj;
	object me;
	string id;
	me=this_player();


	if (!me)
		return 0;
	id=me->query("id");

	file = file[0..10] + file[16..];
	sscanf(file,"/d/phoenix/%s/%s",id,file);
	file = "/d/phoenix/"+file;

	if (debug == 1)
		write(file);

	if (debug == 1)
		write(HIW"\n"+this_player()->query("id")+NOR);

	obj=new(file);
	if (!obj)
		return 0;
	
	obj->set("owner",id);
	// essayer de rappeler cet objet
	add("#"+id,({ obj }) );

	return obj;
}


int destruct_area(string id)
{
	object *l;
	int i;
	l=query("#"+id);

	CHANNEL_D->do_sys_channel("sys",sprintf("Destruct Annie Virtual Area"));
	CHANNEL_D->do_sys_channel("sys",sprintf("Destruct Area: Phoenix - %s",id));


	if (!sizeof(l))
		return 7;
	for (i=0;i<sizeof(l) ; i++)
		if (l[i])
			if (objectp(l[i]))
				destruct(l[i]);
	return 9;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/



/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
