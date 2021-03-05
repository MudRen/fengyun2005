#include <ansi.h>
inherit ROOM;

void create()
{

	set("class","official");

  set ("short", HIW"镜之回廊"NOR);

   set("long", HIR BLK @LONG

　　天兵照雪下玉关，
　　　　虏箭如沙射金甲
　云龙风虎尽交回，
　　　太白入月敌可摧

LONG
NOR    );
    set("exits", ([ 
	"down" : "/d/fy/mirrorgallery",
      ]));

  	set("objects",([
		__DIR__"npc/"+query("class") : 1,
	]));


	set("no_fly",1);
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",240);
	set("coor/z",20);
    set("map","fynorth");
    setup();
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

