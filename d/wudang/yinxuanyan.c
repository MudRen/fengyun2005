// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "隐仙岩");
	set("long", @LONG
走到这里，已是武当山腰。在这里仰望浮云，俯视流水。当真有“荡胸生层云”
的体会。回过身来，但见天尽处，落日熔金，暮云合壁，艳丽无方。
LONG
	);
	set("exits", ([
        "eastup" : __DIR__"tianzhufeng",
	]));

	set("objects", ([
		__DIR__"npc/shui2" : 1,
   ]) );



	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",40);
	setup();
}

void reset()
{
    object shui, ob;
    
    shui = present("shui ruxi",this_object());
    if (shui)	
	{	if (!shui->query("real_shui"))	// fake SHUI
	    {
			if (!random(8))	{				
				shui->ccommand("sigh");
				message_vision(HIC"\n你眼前一花，那清丽的女子已不知从何处握出一把浅红色的短刀。\n"NOR,shui);
				ob = new(__DIR__"npc/shui");
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
    		message_vision(CYN"水如昔手中刀光一闪，刀意未尽，刀影已不见，轻得就像一阵微风拂过。\n"NOR,shui);
    		destruct(shui);
    		return;
    	}	
    }
    ::reset();
}

