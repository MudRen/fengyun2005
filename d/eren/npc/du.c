#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
inherit INQUIRY_MSG;

void create()
{
        set_name("杜老爹", ({ "du laodie" }) );
        set("gender", "男性" );
        set("age", 60);
        set("long","
杜老爹据说是血手杜杀的堂叔，不过大家最感兴趣的还是他制作的暗
器，相传老爹年轻时在唐门和霹雳堂里是领班工匠，端的是赫赫有名。\n");

		set("combat_exp", 800000);
        
        set("inquiry", ([
        	"毒蒺藜":	"毒蒺藜伤人心神，需１００级无有之术才能掌握使用诀窍。\n",
        	"掌心雷":	"掌心雷伤人气血，需５０级无有之术才能掌握使用诀窍。\n",
        	"冰魄神针": "冰魄神针令人瘫软，需１００级无有之术才能掌握使用诀窍。\n",
        	"无有之术":	"以无形入有间，这是我这暗器的发射之道。\n",
        ]));
        
       	set("chat_chance", 1);
        set("chat_msg", ({
        	"杜老爹一字一顿说：若想用我的暗器，就必须学会"YEL"无有之术"NOR"。\n",	
        }) );
        
        set_skill("unarmed",100);
        set_skill("changquan",200);
        set_skill("puti-steps",150);
        set_skill("dodge",100);
        set_skill("move",100);
        map_skill("unarmed","changquan");
        map_skill("dodge","puti-steps");
        map_skill("move","puti-steps");
                
        set("attitude", "friendly");
        set("vendor_goods", ([
               __DIR__"obj/zhen": 10,
               __DIR__"obj/lei": 10,
               __DIR__"obj/jili": 10,
        ]) );
        setup();
        carry_object("/obj/armor/cloth",([	"name": "工匠服",
    						"long": "一件油迹斑斑的工匠服。\n",
    						 ]))->wear();    
}

void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");
}


void reset(){
	        set("vendor_goods", ([
               __DIR__"obj/zhen": 10,
               __DIR__"obj/lei": 10,
               __DIR__"obj/jili": 10,
        ]) );
}