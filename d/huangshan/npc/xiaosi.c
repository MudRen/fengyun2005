inherit NPC;
#include <ansi.h>

void create()
{
        object armor,weap;
        set_name("小厮", ({ "xiao si" }) );
        set("gender", "男性");
        set("age", 25);
        set("long","太湖二十四舵的总舵把子王震湘王老爷子手下的贴身小厮。\n");
        	  
        set("attitude", "friendly");
        set("score", 0);
        set("class","yinshi");
        
        set("combat_exp", 2000000);        
        
	set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               (: perform_action ("whip.tianleiyiji") :),
        }) );
    
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 160);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
        set_skill("whip",160);        
        set_skill("qidaoforce", 150);
	set_skill("five-steps",120);
	set_skill("thunderwhip",140);
	set_skill("dragonstrike",140);
                
        map_skill("unarmed","dragonstrike");
        map_skill("force", "qidaoforce");
        map_skill("dodge","five-steps");
        map_skill("move","five-steps");
        map_skill("whip","thunderwhip");
        map_skill("parry","thunderwhip");
        
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();
	
	weap=new("/obj/weapon/whip");
	weap->set_name("短马鞭",({"whip"}) );
	weap->move(this_object());
	weap->wield();
	
	armor=new("/obj/armor/cloth");
	armor->set_name("灰布衣",({"cloth"}) );
	armor->move(this_object());
	armor->wear();
}
