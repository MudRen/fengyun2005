#include <ansi.h>
inherit ROOM;

void create()
{

	set("class","wudang");

  set ("short", HIY"镜之回廊"NOR);

   set("long", WHT @LONG

　　　　　　 几回问卜敲天地　

　　　一次求签定苍茫

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

