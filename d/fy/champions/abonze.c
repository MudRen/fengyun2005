#include <ansi.h>
inherit ROOM;

void create()
{

	set("class","bonze");

  set ("short", HIY"镜之回廊"NOR);

   set("long", WHT @LONG

　　　　　　 无奈失题说弦管　

　　　尘缘旧事亦消磨

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

