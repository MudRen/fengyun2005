// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "福威镖局");
        set("long", @LONG
一座建构宏伟的宅第之前，左右两座石坛中各竖一根两丈来高 的旗杆，
杆顶飘扬青旗。右首旗上黄色丝线绣着一头张牙舞爪、神态威猛的雄狮，
旗子随风招展，显得雄狮更奕奕若生。雄狮头顶有一对黑丝线绣的蝙蝠
展翅飞翔。左首旗上绣着 “福威镖局”四个黑字，银钩铁划，刚劲非凡。
LONG
        );
	set("exits",([
  		"north" : __DIR__"xidajie1",
  		"south" : __DIR__"fuweibiaoju2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}