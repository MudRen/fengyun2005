#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("庄丁甲" , ({ "guard" }) );
	set("long", "一个普普通通的汉子，是负责白云山庄巡视和防卫的。\n");
	
	set("attitude", "friendly");
	set("title",WHT"白云山庄"NOR);
	set("age", 18+random(10));
        set("gender", "男性" );
	set("group","baiyunzhuang");
	        
	set("combat_exp", 1500000+random(500000));
	
	set("chat_chance", 1);
    set("chat_msg", ({
        	"庄丁焦急地说：喜筵马上就要开始了，怎么花鼓队还没到？\n",
        }) );
	
	set("inquiry", ([
             "喜筵" : "今天是大少爷的喜庆之日，只有有请柬的才能入席。\n",
             "请柬" : "今天是大少爷的喜庆之日，只有有请柬的才能入席。\n",
             "feast": "今天是大少爷的喜庆之日，只有有请柬的才能入席。\n",
             "wedding": "今天是大少爷的喜庆之日，只有有请柬的才能入席。\n",
             "花鼓队":	"老爷特地从内地请来得，这会儿该到了吧，是不是路上出了什么事儿。\n",
       	]));
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );

	auto_npc_setup("wang",150,120,1,"/obj/weapon/","fighter_w","qingfeng-sword",1);
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "白色紧身衣",
    						"long": "白云山庄家丁穿的衣服。\n",
    						 ]))->wear();    
}
