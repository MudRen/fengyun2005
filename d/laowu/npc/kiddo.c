#include <ansi.h>
inherit NPC;
void smart_fight();

int stone();
int stone1();
int stone2();
int stone3();
int stone4();
int stone5();

void create()
{
        set_name("言小小", ({ "bad kid" }) );
        set("title",WHT"阴阳童子"NOR);
        set("gender", "男性" );
        set("age", 1+ random(10));
        set("long", "这个童子身材矮小，却长着一张成人的脸，充满了阴鹜之气。\n");
        set("combat_exp", 3500000);
        set("class","shenshui");
        set("reward_npc", 1);
    	set("difficulty", 5);
		set("no_busy",8);      
        set("inquiry", ([
        	"stone" : (: stone :),
        	"五彩灵石" : (: stone :),
        	"天灵翡翠" : (: stone1:),
        	"碧海蓝心" : (: stone2:),
        	"幽冥紫晶" : (: stone3:),
        	"蛰龙赤丹" : (: stone4:),
        	"凝露黄石" : (: stone5:),
        	"春之痕" : (: stone1:),
        	"海之角" : (: stone2:),
        	"风之云" : (: stone3:),
        	"沙之底" : (: stone4:),
        	"天之涯" : (: stone5:),
        ]));
        
        set("chat_chance", 1);
       	set("chat_msg", ({
			"言小小说：“你想知道五彩灵石秘密么？我可以告诉你，但我必须杀了你。”\n",
		}) );
                         
        set_skill("unarmed", 180);
        set_skill("force", 180);
        set_skill("longlife-force", 140);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("move", 180);
        set_skill("literate",120);
        set_skill("nine-moon-steps", 200);
        set_skill("nine-moon-claw", 180);
        set_skill("perception", 100);
		set_skill("kwan-yin-spells",130);
        set_skill("spells", 150);

		map_skill("move","nine-moon-steps");
        map_skill("spells","kwan-yin-spells");       
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "longlife-force");
                
		setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/hesan");
}

int stone(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
		message_vision(YEL"$N说：“这个数吧。。。不然。。。。”\n"NOR,ob);
		return 1;
	}
	message_vision(YEL"$N说：“太古时，共工撞倒撑天的不周山，女娲炼五彩灵石以补苍天，曾
令五灵神将在天之涯、海之角、风之云、沙之底、春之痕各处收集这五色灵石，
这五彩灵石分别是：天灵翡翠、碧海蓝心、幽冥紫晶、蛰龙赤丹、凝露黄石。
传说任何人如果能得到其中的一种，都能从中得到神奇的灵异力量。” \n"NOR,ob);
	message_vision(YEL"$N说：“这个书上写的明明白白。。。”\n",ob);
	command("heihei");
	me->delete_temp("badkid/bribe");
	return 1;
}

int stone1(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
		message_vision(YEL"$N说：“这个数吧。。。”\n"NOR,ob);
		return 1;
	}
	tell_object(me,HIG"
言小小打了个哈哈：天灵翡翠在春之痕，这个几百年前就有人知道了。不过，
岁月沧桑，乌龟死了，核桃树谢了，绿盒子也被偷了。。。。

言小小说：“谁偷的我可不知道，我可没加到才智。\n\n"NOR);
	me->delete_temp("badkid/bribe");
	return 1;
}

int stone2(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
		message_vision(YEL"$N说：“这个数吧。。。”\n"NOR,ob);
		return 1;
	}
	tell_object(me,HIB"
言小小说：“碧海蓝心在海之角，这个海。。。” 
言小小吟道：“谁知十斛鲛人泪，不化明珠化血痕。所以这个海边会有人，
	      
	      一个美人。
	      
	      美人如玉，玉如美人，
	      美人不是用来杀的，而是用来疼的，
	      无论多锋利的武器，也比不上那动人的一笑。
    	      只有笑才能真的征服人心。
    	      所以当你懂得这道理，就应该收起你的剑来多笑一笑!

	      不过，美人和丑八怪，也就是那么一线的距离。”
	
言小小拍了拍你的肩膀说：老弟，到时候就看你的定力如何了。
	
	"NOR);      	
	
	me->delete_temp("badkid/bribe");
	return 1;
}

int stone3(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
		message_vision(YEL"$N说：“这个数吧。。。”\n"NOR,ob);
		return 1;
	}
	tell_object(me,HIM"
言小小说：幽冥紫晶在风之云，风之云就是风云城。这个东西很伤脑筋，很伤
脑筋，我就不成。前些天花了十两金子买了个机器人，没想到结果还是不成。

言小小浑身一哆嗦，仿佛大白天见了厉鬼，不吭气了。\n\n"NOR);
	me->delete_temp("badkid/bribe");
	command("sigh");
	return 1;
}

int stone4(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
		message_vision(YEL"$N说：“这个数吧。。。”\n"NOR,ob);
		return 1;
	}
	tell_object(me,RED"
言小小说：就像蛇到了冬天，便要蛰在地下一样，蛰龙在沙之底。

	第一次见到它很难，第一次杀它更难，因为它是龙，不是人。
		
	所有的对手都会有弱点，即使是龙也不例外。
		
	这本是个很简单的道理，可是很多人都不明白，或者说，不屑
	于去明白，当他们明白的时候，他们已经成了死人。
		
	死人也能够说话，如果你仍然听不懂，那你也可以死了。

\n"NOR);
	me->delete_temp("badkid/bribe");
	return 1;
}

int stone5(){
	object me,ob;
	ob= this_object();
	me=this_player();
	if (!me->query_temp("badkid/bribe",1)){
		message_vision(YEL"$N看着$n狡猾地笑了起来，张开手向$n翻了两下。。。\n"NOR,ob,me);
		message_vision(YEL"$N说：“这个数吧。。。”\n"NOR,ob);
		return 1;
	}
	tell_object(me,YEL"
言小小说：“这凝露黄石其实是个很简单的谜，
	    黄山的采石峰就是你该去的地方，最好再带上掘地的工具。
	    一件稀世的珍宝，我已经替你指明了方向，还有比这更容易的事么？
	   
	   不过即使我知道了这个秘密，
	   我言小小仍然还是言小小，李寻欢仍然还是李寻欢。
	   
	   就如一个练武三十多年的人，会忽然死在一个残疾的孩子手里，
	   这世上有些东西，并不会因为你聪明或者勤奋而改变。
	   	   
	   明白了这个道理，你才会真正快活起来。”
	   \n"NOR);
	me->delete_temp("badkid/bribe");
	return 1;
}


int accept_object(object who, object ob)
{
	if (ob->value()>=1000) {
		command("giggle");
		command("say 有问题就问吧。");
		who->set_temp("badkid/bribe",1);
		return 1;
	} 
	
	command("say 这么点。。开玩笑吧。");	
	return 0;
	
} 