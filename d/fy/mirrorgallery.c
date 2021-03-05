#include <ansi.h>
inherit ROOM;

void create()
{


  set ("short", HIW"镜之回廊"NOR);

   set("long", HIR BLK @LONG
镜廊的入口之处摆放著一面洁然萤色的明镜，传说中这是一面可以映照出世间一
切事物真相的鏡子，惟独无法映出当下眼前的事物。进入这里的人，都要经过一番挑
战，才能真正的战胜自我，悟出武学的奥秘。
LONG
NOR    );
    set("exits", ([ 
  "up" : __DIR__"mirrorgallery",
	"down" : __DIR__"hall",


      ]));

  	set("objects",([
		AREA_GUANWAI"npc/champion": 1,
//		__DIR__"champions/c"+query("floor") : 1,
	]));


	set("no_fly",1);
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",240);
	set("coor/z",10);
    set("map","fynorth");
    setup();
}




void init()
{
	add_action("do_north", "go");
}

int valid_leave(object who, string dir){
	
	if (dir == "down")
	{
		tell_object(who, HIW"你正离开比武地区，将会有２秒的停滞以清除所有战斗状态。\n\n"NOR);	
		who->remove_all_killer();
		who->perform_busy(1);
	}
	return ::valid_leave();
}

int do_north(string arg)
{
    object room, me;
	string str;
    if (arg == "up") {
	me = this_player();
	str = me->query("class");
	if (!str || str == "")
		str="mirrorgallery";
	else
		str = __DIR__"champions/a"+str;

	if (!room= find_object(str))
	    room=load_object(str);
	if (room)
		me->move(room);
		return 1;
    }
    return 0;
}





/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/

