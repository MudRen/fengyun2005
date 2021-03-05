#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "瓦房");
        set("long", @LONG
瓦房外精致已极，屋中布置得更是井然有条，墙上挂着一幅梅花傲雪图，虽只
是寥寥数笔，却把梅花的凌风傲骨，表露无遗，左上角印着一枚鲜红的图章，上书
七妙神君--梅。奇怪的是诺大的几间屋子，都空旷地没有人声，向南是一扇暗紫色
的大门。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"meilin",
		"west" : __DIR__"studyroom",
	]));
        set("objects", ([
        __DIR__"npc/hou" : 1,
                        ]) );

    set("indoors", "fengyun");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    setup();
	create_door("south", "door","暗紫色的大门", "north", DOOR_CLOSED);
}

/*
void init(){
	if(!doors["south"]["status"]) {
		this_player()->ccommand("close door");
	}
}*/

int answer_door(){
	object hou;
	
	if(hou = present("hou", this_object())){
		hou->ccommand("open door");
	}
	 else {
		hou = new(__DIR__"npc/hou");
		hou->move(this_object());
		hou->ccommand("open door");
	}
	return 1;
}

int valid_leave(object player, string dir)
{
	object hou;
	if (dir == "west" && !player->query("marks/梅山民") && hou = present("hou",this_object()))
	{
		message_vision("$N道：“这位"+RANK_D->query_respect(player)+"，内室是私人的地方，请留步！“ \n",hou);
		return notify_fail("中年汉子挡住了去这个方向的路\n");
	}
	if (dir == "west" && player->query("marks/梅山民") && hou = present("hou",this_object()))
	if(!player->query("m_killer/厉鹗") || !player->query("m_killer/赤阳道长")
		|| !player->query("m_killer/苦庵上人") || !player->query("marks/谢长卿"))
	{
		message_vision("$N道：“这位"+RANK_D->query_respect(player)+"，梅大哥被五大掌门暗算，正在内室静养。强敌环伺，此患不除，不敢随便让人入内。“ \n",hou);
		return notify_fail("中年汉子挡住了去这个方向的路\n");
	}
	return ::valid_leave(player,dir);
}
