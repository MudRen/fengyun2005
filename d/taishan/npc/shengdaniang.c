inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("盛大娘", ({ "sheng daniang","daniang" }) );
        set("nickname",HIR "散花玄女" NOR);
        set("gender", "女性");
        set("age", 65);
        set("long","满头银发如丝的盛家庄女主人，昔年人称‘散花玄女’的盛大娘。\n");
      
      	set("chat_chance", 1);
		set("chat_msg", ({
		 	"盛大娘说：我三个媳妇一个接着一个都死在大旗门人的手里，害得我这儿子十余年都不愿再娶亲了。\n",
		}) );
	  
        set("score", 2000);
        set("class", "huashan");
        set("reward_npc", 1);
		set("difficulty", 5);
        
        set("combat_exp", 3700000);        
                
        set("chat_chance_combat", 100);
   	 	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
     	}) ); 		

		auto_npc_setup("wang",180,160,0,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
        setup();
        carry_object(__DIR__"obj/n_stone")->wield();
		carry_object("/obj/armor/cloth")->wear();
}
