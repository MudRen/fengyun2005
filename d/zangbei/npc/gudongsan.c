#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("古董三",({"gudong san","gudong"}));
	set("long", "一个头发有些花白的小老头儿，两个眼睛骨碌碌地转。\n");
	set("nickname",YEL"夺宝奇兵"NOR);
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 5000000);
	set("gender","男性");
	
	set("inquiry", ([
   		"紫晶宝石":		"宝石？拿来让我看看。\n",
   		"打水的妇人":	"我在这儿住了快一个月了，没人来打过水。\n",
   		"极乐之星":		"极乐之星有两颗，一紫一黄，乃是西域龟兹王之护国之宝。\n",
   		"龟兹王":		"龟兹王富甲天下，等他死了我一定去拜访拜访。\n",	
   		"英穷死":		"不是穷死，是琼斯！！！\n",
   		"夺宝奇兵":		"。。。。。。\n",
   	]));
   	
   	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
     }) );
   	
   	auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","thunderwhip2",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/armor/hat",([	"name": "西式毡帽",
    						"long": "一顶中央微陷，两头翘起的毡帽，似乎是舶来品。\n",
    						"value": 0,
    						 ]))->wear();    
	carry_object("/obj/weapon/whip",([	"name": "长皮鞭",
    						"long": "一条长长的皮鞭，不用时可以卷在腰间。\n",
    						"value": 0,
    						 ]))->wield();   
}


int accept_object(object who, object ob)
{
	object stone;
	if(ob->query("name") == WHT"温玉"NOR) {
 	 	if (REWARD_D->riddle_check(who,"紫晶之谜")!=3) {
 	 		command("say 假的、假的、不值一文！");
 	 		return 0;
 	 	}
 	 	command("giggle");
 	 	command("say 你上了我媳妇儿的当了，这玉石是用碱水泡出来的，不值分文！");
 	 	message_vision(CYN"$N的眼睛骨碌碌地一转。\n",this_object());
 	 	command("say 不过，你既然找到我了，可不能将我藏身之处说出去。");
 	 	command("say 我媳妇儿啊，什么都好，就是。。太。。厉害了，我得在这儿喘口气。");
 	 	command("say 恩，要我帮什么忙就开口吧。");
 	 	REWARD_D->riddle_set(who,"紫晶之谜",4);
 	 	return 1;
 	 }
 	 
 	 if (ob->query("name") == HIM"紫晶宝石"NOR&& ob->query("jile")==1){
 	 	if (REWARD_D->riddle_check(who,"紫晶之谜")!=4) {
 	 		command("say 此物来历不明，快快脱手，免遭杀身之祸！");
 	 		return 0;
 	 	}
 	 	message_vision(CYN"$N眯起眼睛看了看"+ob->name()+CYN"，嘿嘿地笑了起来。\n"NOR, this_object());
 	 	message_vision(CYN"$N双手一用力，啪地一声竟然将"+ob->name()+CYN"掰成了两半，
碎裂的玉石下，竟然是一块鹅卵般大小的宝石，散发着幽幽的紫光。\n"NOR,this_object());
 	 	command("say 小子，你是身在宝山不识宝啊！");
 	 	command("say 此物乃西域龟兹王所有，数月前为人所盗，没想到竟然流落到你的手中。");
 		REWARD_D->riddle_done(who,"紫晶之谜",20,1);
 		stone = new("/obj/gem/stargem2");
 		stone->set("item_owner", who);
 		stone->move(who);
 		return 1;
 	}
 			 	
 	command("say 我古董三只拿死人的东西，活人的我不要。");
 	return 0; 	
 	 	
} 

	
		