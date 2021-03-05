
inherit NPC;
#include <ansi.h>
void create()
{
	object weapon;
        set_name("小随从", ({ "servant" }) );
        set("gender", "男性" );
        set("long","
这随从长得相当清秀，下巴上一点胡渣子都没有，说话细声细气。
"
	);
	
        set("age", 24);
        set("attitude","friendly");
        
        set("combat_exp", 0);
        
        set("score", 20000);

		set("no_arrest",1);

		set("chat_chance", 1);
        set("chat_msg", ({
                "随从低声道：公子，这人看起来不怀好意，您还是．．．\n",
                "随从斥道：大胆刁民，竟敢对．．无礼！\n",
                "随从慌慌张张地看了周围几眼，低声道：公．．子，我们还是早点回去吧。\n",
        }) );
        

        setup();
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("银袖纹麝衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("孔雀尾羽帽", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();

}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
