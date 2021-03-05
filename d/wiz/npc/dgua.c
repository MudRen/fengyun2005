//Tushen@Fygroup
//Based on Silencer's code.Copyrights all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("好好", ({ "haohao" }) );
        set("gender", "女性");
        set("age", 23);     
      	set("chat_chance", 1);
	set("chat_msg", ({
"好好脉脉与屠神对视，眼中蕴含着千种柔情，万般蜜意。\n",
"好好恶狠狠的瞪了无言一眼。"
	}) );
        set("attitude", "friendly");
        set("title",HIG"白云千载空悠悠"NOR);
        set("nickname", HIG"物换星移几度秋"NOR);
        set("score", 200000);
        set("reward_npc", 1);
		    set("difficulty",50);
		    set("class","baiyun");
        set("death_msg",CYN"\n$N惊道：屠神救我！\n"NOR);
        set("combat_exp", 16000000);        
        
    	set("perform_busy_d", "bat/dodge/fengyu-piaoxiang/zonghengsihai");
		set("perform_weapon_attack", "baiyun/magic/music/bainiao");
		set("perform_weapon_attack2", "baiyun/magic/music/guanglingsan");
		set("perform_weapon_attack3", "demon/blade/heavendance/yuexierenjing");
    	set("perform_buff_1", "berserker/force/gaunforce/damageup");
		
		set("skill_type_w", "blade/heavendance");
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 270);
        set_skill("perception", 300);
        set_skill("force", 270);
        set_skill("spells", 300);
        set_skill("unarmed", 280);
        set_skill("parry", 300);
        set_skill("dodge", 280);
        set_skill("magic", 300); 
        set_skill("blade", 300);
        
        set_skill("gaunforce", 180);
	    set_skill("fengyu-piaoxiang", 200);
        set_skill("heavendance", 230);
        set_skill("music", 200);
        
        map_skill("blade","heavendance");
        map_skill("force", "gaunforce");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        map_skill("parry","heavendance");
        map_skill("magic","music");
        setup();

    	carry_object("/obj/armor/blade",([	
    						"name":  "欢颜",
    						"long": "恩，没想好写什么。\n",
    						 ]));
    						 
    	carry_object("obj/music/chunlei");
    	
    	carry_object("/obj/armor/cloth",([	
    						"name":  "灵禽羽衣",
    						"long": "一件百鸟羽毛所织成的衣服，透出奇异的光芒。\n",
    						 ]))->wear();  
}
int direct()
{   
    	message_vision("好好悠悠的望着远方：那，早已经是很久以前的事情，
    	过去的，就让它过去好了。\n\n",this_object());
    	return 1;
}

