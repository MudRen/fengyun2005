// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "朝阳峰巅");
    set("long", @LONG
峰顶长满高大的桧松，似在峰顶盖了块绿色的毯子，林中浓荫蔽日，树下石径
上铺满了松针。无风的时候，走在石径上，可以清楚的听见松针断裂的声音；然而
当山风吹来，穿过林间只听松涛阵阵，此起彼伏，又是一番景色。
LONG
    );
    set("exits", ([ 
	"down" : __DIR__"chaoyang",
      ]));
    set("objects", ([
	__DIR__"obj/pineneedle" : 1,
	__DIR__"obj/pinetree" : 1,
	"/obj/animal/songshu" : 1,
	__DIR__"npc/suu2" : 1,
      ]));  
    set("outdoors", "huashan");

    set("coor/x",-4);
    set("coor/y",-53);
    set("coor/z",123);
    setup();
}


void reset()
{
    object shui, ob;
    
    shui = present("suu xiaoxiao",this_object());
    if (shui)	
	{	if (!shui->query("real_suu"))	// fake SHUI
	    {
			if (!random(8))	{				
				shui->ccommand("sigh");
				message_vision(HIG"\n苏小晓慢慢套上一双雕花指甲，抬起头对你幽幽一笑：你是不是，已经，等我很久了？\n\n"NOR,shui);	
				ob = new(__DIR__"npc/suu");
        		ob->move(this_object());
        		this_object()->set("boss_out",time());
        		destruct(shui);
        		return;
			}
		}
		else if (query("boss_out") + 3600 > time() || shui->is_fighting())
	    	return;
    	else {
    		shui->ccommand("sigh");
    		message_vision("$N慢慢走进山林中消失了。\n",shui);
    		destruct(shui);
    		return;
    	}	
    }
    ::reset();
}

