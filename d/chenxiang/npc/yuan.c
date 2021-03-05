inherit SMART_NPC;
void create()
{
        set_name("袁紫霞", ({ "yuan zixia", "yuan"}) );
        set("gender", "女性" );
        set("age",22);
        set("per",50);
        set("long", "迷人的眼睛，羞涩的笑容，瓜子脸上不施脂粉，一身衣裳却艳如紫霞。\n");
        set("combat_exp", 1600000);
        
		set_skill("move",250);
		set_skill("unarmed",100);
		set_skill("force",60);
		set_skill("dodge",250);
		set_skill("liuquan-steps",100);
		set_skill("yunwu-strike",100);
		set_skill("parry",100);
		
		map_skill("unarmed","yunwu-strike");
		map_skill("dodge","liuquan-steps");
		map_skill("move", "liuquan-steps");
	
		set("perform_busy_u", "huangshan/unarmed/yunwu-strike/miwu");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
        	
        set("chat_chance", 1);
        set("chat_msg", ({
		"袁紫霞美目流转，拿起刀，又跺了跺脚放下刀来。\n",
        	"袁紫霞美目一转，脸红得象天边的晚霞，喃喃道：白玉京啊，我。。我。。\n我对你怎么样，你应该清楚。\n",
        }) );
        set("inquiry",([
        	"白玉京"  :"他啊。。。哎。。男人难道都象他那样猪头么？\n",
        	"bai"  :"他啊。。。哎。。男人难道都象他那样猪头么？\n",
        	"bai yujing"  :"他啊。。。哎。。男人难道都象他那样猪头么？\n",
                ]) );
        
		setup();
    	carry_object("/d/chenxiang/npc/obj/purpleskirt")->wear();
}

