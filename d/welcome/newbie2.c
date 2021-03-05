
inherit ROOM;
#include <ansi.h>

void create ()
{
  	set ("short", HIR"十戒碑"NOR);
  	set ("long", @LONG
未行数步，但见四下风云变幻，浓雾蔽目，不见前路，是前？是进？是左？是
右？你不禁犹豫踯躅，四下探究，擦拭掉路边石碑上厚厚的青苔，赫然露出密密麻
麻的数列蝇头小楷，你屈身凝目，细细读了起来，上书：正所谓无规矩不成方圆，
[37mｈｅｌｐ　ｒｕｌｅｓ[32m给出风云规则，如果你同意遵守所列规则，输入ａｇｒｅｅ
正式进入风云登陆，否则可随时退出（ｑｕｉｔ）。
LONG);

 	set("no_magic",1);
	set("no_fight",1);
  	set("exits", ([ /* sizeof() == 1 */
  		"agree" : __DIR__"newbie3",
  		
	]));
  
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",900);
  	
  	setup();
  
}