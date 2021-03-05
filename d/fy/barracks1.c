#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "东营");
    set("long", @LONG
一排暗褐色的平房方方正正，这里是驻守风云城兵士的营地，虽然说自两年前大盗
祁连山落网以来成立还没出过什么大案，但京城之内天子脚下，上自九门提督下到
绿营小卒，无不兢兢业业。近来金钱帮势力日盛，京城里江湖人物来往众多，兵士
们日夜巡查，这营地里少了许多往日的操练之声。		
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"ecloud5",
      ]));


    set("indoors", "fengyun");
    set("coor/x",280);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}

