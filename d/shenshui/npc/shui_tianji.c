
inherit NPC;
inherit F_MASTER;

/*只听这人在耳畔轻轻道：“乖宝宝，看姑姑将这呆木头捉弄得有趣么?”语声柔媚清
脆，远胜出谷新鸳。

 只觉水天姬的手掌，在他身上轻轻抚摸，只要被她摸着的地方，都有说不出的舒服，生
似她双手都有着神秘的魔力，方宝儿若非年龄幼小，只要被这双手轻轻一摸，使要神魂飘
荡，变得痴了

蚀心化骨焦烂骸丧门火
“虎”地一声，各只长筒俱喷出一道烈火团，但火焰成碧磷色，

*/

int leave();

#include <ansi.h>
void create()
{
    	set_name("水天姬", ({ "shui tianji","shui", "master", "master shui"}) );  
    	set("gender", "女性");
    	set("class", "shenshui");
    	set("age", 21);
    	set("long","
秋波如水，娇圈如花的绝色美女。尤其是她面上所带的那份笑容，更可
令任何人见了都会神魂颠倒，不能自己，正是五行魔宫宫主白水娘娘的
女儿，江湖中黑白二道人见人愁的水天姬。");
    	
    	set("attitude", "peaceful");
    	set("class", "shenshui");
    	set("apprentice_available", 5);
    
    	create_family("神水宫", 12, "少宫主");
    	set("rank_nogen",1);
        set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"采莲女","侍女","小仙女","仙女","绛衣仙子","橙衣仙子",
			"青衣仙子","白衣仙子","神姬","仙姬","魔姬","妖姬",RED"绝代妖姬"NOR,
			RED"九阴姹女"NOR,RED"癸宗传人"NOR,HIR"癸宗宗主"NOR}));
			
    	set("reward_npc", 1);
    	set("difficulty", 5);
    	set("inquiry", ([
        	"leave" : (: leave :),
    	]));  
    
    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: perform_action, "dodge.lianhuanbu" :),
    	}) );
    
    	set("combat_exp", 5000000);
    	set("score", random(90000));
    	
    
    	set_skill("unarmed", 150);
    	set_skill("sword", 200);
    	set_skill("force", 150);
    	set_skill("parry", 150);
    	set_skill("dodge", 150);
    	set_skill("literate",100);
    	set_skill("move",150);
    	set_skill("chanting",150);
    	set_skill("foreknowledge",100);
    	set_skill("perception",100);
    	
    	set_skill("nine-moon-spirit",150);	
    	set_skill("nine-moon-steps", 150);
    	set_skill("nine-moon-claw",  150);
    	set_skill("nine-moon-force", 150);
    	set_skill("nine-moon-sword", 180);

    	map_skill("dodge",   "nine-moon-steps");
    	map_skill("unarmed", "nine-moon-claw");
    	map_skill("force",   "nine-moon-force");
    	map_skill("sword",   "nine-moon-sword");
    	map_skill("move",     "nine-moon-steps");
    
    	set_temp("nine-moon-force_poison", 340);
    	set_temp("damage_shield/type","kee");
		set_temp("damage_shield/amount",180);
		set_temp("damage_shield/msg",MAG"$n似乎沾上了$N周围的毒雾，手脚开始不灵便起来。\n"NOR);
	
    	set_temp("apply/dodge", 100);
    	set_temp("apply/attack", 100);

    	setup();
    	carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
 		object girl;

   		if( ob->query("gender") != "女性" )
    		message_vision(CYN"水天姬笑得花枝乱颤，“你一个大男人，却想拜我做师傅，羞也不羞？”\n"NOR, ob);
		else {
    		message_vision(CYN"水天姬笑嘻嘻地说：“既然你这么诚心，我就收你做徒弟吧。”\n"NOR, ob);
        	command("recruit " + ob->query("id") );        	
		}
		/*
   	else if (ob->query("marks/shenshui/小白鼠") || ob->query("marks/shenshui/胜天姬")) {
    		message_vision(CYN"水天姬笑嘻嘻地说：既然你这么诚心，我就收你做徒弟吧。”\n"NOR, ob);
        	command("recruit " + ob->query("id") );
    	
	} else 	{
        	message_vision(CYN"水天姬笑嘻嘻地说：我哪有那么多工夫收徒弟。。
这样吧，你我比试比试，如果你够机灵，我就收你。”\n"NOR, ob);
		command("fight "+ ob->get_id());
   	}*/
}

void init()
{	
		object ob;
		::init();
		if( interactive(ob = this_player()) && !is_fighting() 
			&& ob->query("class")=="shenshui"
			&& ob->query("level")< 30 			// Each Login one..don't think they can carry over
			&& !ob->query_temp("marks/pfm/ss_shui")) {
				remove_call_out("greeting");
				call_out("greeting", 1, ob);
		}
		add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="shenshui") return 0;
	message_vision(CYN"$N冷笑了一声。\n"NOR, this_object(),this_player());
	message_vision(CYN"$N说：想走可以，但从此不能在江湖上使用九阴神功。\n"NOR,this_object(),this_player());
	return 1;
}

void killed_enemy(object who)
{
    	command("say 哎哟，怎么一下就挂了！\n");
}

void	greeting( object ob)
{
	object pipe;
	
	if (!ob || environment(ob) != environment())	return;
		
	if (ob->query("marry"))
	{
		message_vision(CYN"$N伸手捏了捏$n的脸蛋说：“乖宝宝长的真可爱，"+ ob->query("marry_name")+
"福气不小啊。”\n"NOR, this_object(), ob);
		return;
	}
	
	if (ob->query("age") > 25)
	{
		message_vision(CYN"$N伸手捏了捏$n的脸蛋说：“一晃都长成大姑娘了，有没有心上人啊？\n"NOR,
				this_object(), ob);
		return;
	}
	
	
	message_vision(CYN"$N伸手捏了捏$n的脸蛋说：“乖宝宝长的可真可爱，将来不知道谁有福气了。”
说罢一把把$n抱在怀里。\n"NOR,this_object(), ob);
	tell_object(ob, YEL"\n你只觉得水天姬的手掌，在你身上轻轻抚摸，只要被她摸着的地方，都有说不出
的舒服，生似她双手都有着神秘的魔力。\n"NOR);
	ob->set_temp("marks/pfm/ss_shui",1);
	// ob->delete("timer/ss_heart");
	tell_object(ob, YEL"\n水天姬轻轻地在你耳边说：乖孩子，姑姑再教你一招，看哪个坏男人敢打你主意！\n"NOR);
	message_vision(CYN"$N往$n怀里塞了件东西。\n"NOR, this_object(), ob);
	pipe = new(__DIR__"obj/pipe");
	if (!pipe->move(ob)) destruct(pipe);
	return;
}	
	
int accept_object(object who, object ob)
{
        if (ob->query("name") == HIM"心事"NOR && ob->query("ss_shui"))
        {
			if ( who->query("level")>= 30 )
			{
				message_vision(CYN"水天姬眨了眨眼说：乖宝宝长大了，这俗物不要也罢。\n"NOR, who);
				return 1;
			}
			
			if (who->query("level")> 24)	// it's the easiest way to remove the mark...
				who->delete_temp("marks/pfm/ss_shui");
			
        	if (ob->query("ammo")<1)
        	{
        		message_vision(CYN"水天姬伸手在"+ ob->name() + CYN"上飞快地拨了几下说，好啦！\n"NOR, who);
				ob->set("ammo", 10);
				who->delete("timer/ss_heart");
				return 0;
        	}	
        
        	message_vision(CYN"水天姬说：" + ob->name()+ CYN"不是还能用么？\n"NOR, who);
    	}		
		return 0;
}