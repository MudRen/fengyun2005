inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIG"风云西城门"NOR);
    set("long", @LONG
西城门阁矮小而破旧，守城卫兵斜戴着红樱帽，搂着长枪在打瞌睡。也许因为
西城区所住皆贫困撩倒之徒，这里的治安和卫生都不是很好。狂风掠过之时，满地
垃圾随风飞舞，夜幕降临之后，惨号和狞笑声此起彼伏。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : "/d/fycycle/fywest",
	"east" : __DIR__"wcloud5",
	"up"   : AREA_FYWALL"wupgate",
      ]));
    set("objects", ([
	__DIR__"npc/wind_soldier": 2, 
	__DIR__"npc/cloud_soldier": 2, 
      ]) );
    set("outdoors", "fengyun");
    set("coor/x",-300);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
}


int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    if( userp(me) && ob=present("garrison", this_object()))
    {
		if( dir == "east")	{
		    inv = all_inventory(me);
		    for(i=0; i<sizeof(inv); i++)	{
			if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
			    return notify_fail(ob->name()+"向你喝道：不可手持兵器入风云城！\n");	
		    }
		}

		if ( dir == "east" && me->is_naked()) {
			if (me->query("age")<=11)
				 tell_object(me,ob->name()+"皱着眉头说：小孩子光着屁股跑来跑去，像什么样子！\n\n");
			else
				return notify_fail(ob->name()+"向你喝道：赤身裸体招摇过市，成何体统！！\n");
		}
	
		if( dir == "up")       {
	    	inv = all_inventory(me);
	    	for(i=0; i<sizeof(inv); i++)
		    {
				if(((string)(inv[i]->name()) == "风云战甲") && (int)(inv[i]->query("equipped")))
			    return 1;
		    }
	    	return	notify_fail(ob->name()+"向你喝道：闲杂人等不可上登护城墙！\n");
		}
    }

	return 1;
}
