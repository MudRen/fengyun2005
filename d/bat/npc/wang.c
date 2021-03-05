inherit NPC;
#include <ansi.h>
void create()
{
    	set_name("王天寿", ({ "wang tian shou","wang" }) );
    	set("title", HIR "九现云龙" NOR);
    	set("gender", "男性" );
    	set("age", 55);
    
    	set("long","
这老人的一双手又黄又瘦，有如枯木，正是淮西鹰爪门的第一高手。二十 
年前已将掌门之位传给了他的侄子王维杰，近年来已很少在江湖走动。 
\n"
        );
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"王天寿颇为神秘的道：阁下知不知道新近江湖上又出了个可怕的人物？\n",
            }) );
    	set("attitude", "friendly");
    
    	set_skill("unarmed", 200);
    	set_skill("move", 80);
    	set_skill("dodge",150);
    	set_skill("parry",150);
    	set_skill("five-steps",100);
    	set_skill("eagle-claw",150);
    	map_skill("unarmed", "eagle-claw");
    	map_skill("dodge","five-steps");
    
    	set("combat_exp", 1000000);
    	
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object(__DIR__"obj/mengui");
}
