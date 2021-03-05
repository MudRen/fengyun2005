// acao.c

inherit NPC;

#include <ansi.h>
void create()
{
		set_name("天无草", ({ "tianwu cao","cao" }) );
		set("gender", "女性" );
		set("age", 21);
        set("title","天宗"+HIG" 柔情刺客"NOR);
		set("long", HIC "\n她长得极美，尤其是那双眼睛，媚得直可以勾人魂魄。\n"+
			"其容色晶莹如玉，映照于红红烛光之下，娇美不可方物。\n"+
			"回眸嫣然一笑，雅如仙子下凡。眼波流转之间，\n"+
			"便把一个少年的心灵，推向梦中极美的境界。\n" NOR);
        set("chat_chance", 5);
        set("chat_msg", ({
            "阿草懒懒一笑道：阿草的刀快？还是阿水的剑快？\n",
     	    "阿草打了个呵欠，左手轻轻掩住樱桃小口，柔声道：我困了。\n",
   	    	"阿草忽然莞尔一笑道: 阿水待会儿又要我杀谁呢？\n",
	    	"阿草无聊地绕着手绢，叹道: 唉，一个人，真没意思。\n",
	    	"阿草伸出白玉雕成一般的小手，托着下巴说: 谁想和我说说话?\n",
	    	"阿草斩钉截铁地说: 嗯，谁要敢欺负我，我就宰了他！\n",

          }) );
		set("combat_exp", 2000000);
		set("attitude", "friendly");
		set("per",100);
		
		set_skill("dodge",300);
        set_skill("unarmed",200);
        set_skill("blade",200);
        set_skill("fall-steps",200);
        set_skill("springrain-blade",200);
        set_skill("meihua-shou",200);
        set_skill("parry", 200);
        map_skill("parry","springrain-blade");
        map_skill("dodge","hawk-steps");
        map_skill("unarmed", "meihua-shou");
        map_skill("blade", "springrain-blade");
        
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
				"阿草幽幽叹道：唉，你这又是何苦呢?\n",
				(: command("say 生有何欢，死亦何忧? 不如就成全了你吧。\n") :),
                (: perform_action, "dodge.luoyeqiufeng" :),
                (: perform_action, "blade.dangshimingyue" :),
                (: perform_action, "unarmed.meihai" :),              
        }) );

        setup();
		carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();
}

void die()
{
	object ob;
	message_vision("\n$N娇喘一口气，说道：大哥会为我报仇的。\n", this_object());
	message_vision("$N说完，化作一缕清风而去。\n", this_object());
	destruct(this_object());
}