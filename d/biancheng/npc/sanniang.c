#include <ansi.h>
inherit SMART_NPC;

int area_chat();
void create()
{
    	set_name("沈三娘",({"shen sanniang","shen","sanniang"}));
	set("title",WHT"人如玉 玉生香"NOR);
   	set("long","
这妇人长身玉立，满头秀发漆黑，一张瓜子脸却雪白如玉。她并不是那种令人
一见销魂的美女，但一举一动间都充满了一种成熟的妇人神韵。无论什么样的
男人，只要看见她立刻就会知道，你不但可以在她身上得到安慰和满足，也可
以得到了解和同情。\n");

     	set("gender","女性");
    	set("age",32);
    	set("group","guo");    	
    	set("per",40);
    	
    	set("combat_exp",9000000);  
    	set("attitude", "friendly");
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	

    	set("chat_chance",1);
    	set("chat_msg",({
		(: area_chat() :),
    	}) );    	    	
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		
    	}) );    	    	
    	
		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","nine-moon-claw",1);
		setup();
    	carry_object("/obj/armor/cloth",([	"name": RED"红绫袄"NOR,
    						"long": "一件红绫袄。\n",
    						 ]))->wear();    
    
}

int area_chat(){
	if (environment(this_object())->query("discussion_shen")) {
		if (random(2)) message_vision("沈三娘俯下身，拔去坟上的几棵杂草。\n",this_object());
			else message_vision("沈三娘怔怔地望着墓碑，一语不发。\n",this_object());
	}else {
		if (random(2))message_vision(name()+"长长叹息了一声，道：“也许我根本不该来的。”\n",this_object());
			else message_vision(name()+"笑了，轻轻道：“你若要找我，应该在没有人的时候来。”\n",this_object());
	}
	return 1;
}


void init()
{	
	object me;

	::init();
	if( interactive(me = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
	add_action("do_answer","answer");
}

void greeting(object me)
{
	object ob, huzi;
	ob=this_object();
	if (environment(ob)->query("discussion_shen")){
		message_vision(YEL"
沈三娘走到坟边，在石碑前跪了下来，良久良久，才站起来，转过身，脸
上挂满了泪痕，每一道泪痕。都不知埋藏着多少凄凉惨痛的往事。\n\n"NOR,ob);
		message_vision(CYN"沈三娘缓缓地对$N说：“我知道你一定会来的。”\n"NOR,me);
		call_out("event2",3,me,0);
		return;
	}
	if( !me || environment(me) != environment() || me->is_fighting()) return;
	if (me->query("marks/wanma/准备杀同伙_ma")) {
		command("say 你是三堂主的红人了，不过，他不喜欢其他人呆在我的屋子里，你还是快出去吧。");
		return;
	}
	if (!me->query("marks/wanma/上楼")) {
		command("say 你快离开，让三堂主看见你想走也走不了了。");
		return;
	}
	huzi=present("xiao huzi",environment(ob));
	if (huzi) {
		message_vision("沈三娘抬起头来，似乎向你使了个眼色。\n",ob);
		call_out("event1",10,me);
	}
	return;	
}

int event1(object me) {
	object huzi,ob;
	ob=this_object();
	if( !me || environment(me) != environment() || me->is_fighting()) 
		return 1;
	huzi=present("xiao huzi",environment(ob));
	if (huzi && !huzi->is_fighting()) {
		command("say 虎子，出去找你公孙叔叔玩一阵。");
		huzi->ccommand("jump");
		huzi->ccommand("south");
		destruct(huzi);
	}
	command("close door");
	message_vision(CYN"
沈三娘说：“我知道你在替三堂主办事，三堂主也很欣赏你。不过，很多
事都并不像表面看起来那么简单。我希望你这次见三堂主前能好好想一想。
此处隔墙有耳，每天早晨我都会去这附近的小山坡，想明白了，你可去那
里找我。”\n"NOR,ob);
	return 1;
}


string *event2_msg=	({
	CYN"
沈三娘凝视着你，忽然道：“你看见了什么？”

你道：“一座坟。”\n"NOR,

CYN"沈三娘道：“你知道这是谁的坟？”

你道：“白天羽、白天勇。。。”\n"NOR,

CYN"沈三娘点点头接着说：”我不姓沈，姓花。神刀堂主白天羽有过一个红粉
知己花白凤，就是我的亲姐姐。十九年前，梅花庵外，一个漫天飞雪的晚
上，白天羽，白天勇两家在踏雪时突遭三十八人围攻。那天的雪下得很大，
地上一片银白，但那战斗结束后，整个一片银白色的大地，竟都被鲜血染
红了。。。。\n"NOR,

YEL"沈三娘越说越慢，声音越来越低沉，每吐一个字都是那么的痛苦。\n"NOR,

CYN"白家的男男女女，老老少少，在那一战中无人生还。凶手皆以黑布蒙面，
但个个武功高强，神刀堂主力战身亡，凶手也只有七个活下来。从那天后，
所有与神刀堂有关系的人都遭到追杀，不几年神刀堂就垮了。\n"NOR,

CYN"我和姐姐东躲西藏，当时姐姐已生下白天羽的儿子，自然是凶手的眼中钉。
幸亏她是魔教公主，在教众的掩护下才幸免于难。但姐姐从此性情大变，
终日不语，只有报仇一念。\n"NOR,

CYN"终于在十年前，我们打探到，这伙凶手内，竟然便有白天羽的结拜兄弟马
空群，所以七年前我改姓换名到万马堂，就是为了证实此事，并打听出其
余凶手的下落。\n"NOR,

CYN"十九年来，姐姐一心一意将孩子抚养长大，指望他为父报仇，没料到，没
料到这个孩子傅红雪竟然不是白天羽的儿子，而白天羽真正的遗孤叶开却
不愿去杀仇人！！！\n"NOR,

CYN"天网恢恢，疏而不漏，杀人者死，这个仇一定要报，马空群和那些凶手一
定要死，出卖兄弟朋友的人一定要死。\n"NOR,

	
});


void event2(object me, int count)
{
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	tell_object(me,event2_msg[count]+"\n");
	if(++count==sizeof(event2_msg))	{
		tell_object(me,HIR"你若愿意为白天羽报仇，你就能成为神刀门的传人。\n\n"NOR);
		tell_object(me,HIY"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ） \n"NOR);
		me->set_temp("marks/wanma/answer_shen",1);
		return;
	}
	else call_out("event2",1,me,count);
	return ;
}

int do_answer(string arg)
{
	object me,ob;
	
	me=this_player();
	ob=this_object();	
	
	if(me->query_temp("marks/wanma/answer_shen")==1) {
		if(arg=="yes") {
			message_vision("\n$N坚定地点了点头说：“如此不义之事，在下虽武功低微，愿尽力而助。”\n"NOR,me);
			message_vision(CYN"沈三娘说：“好，有大侠相助，马空群与其同伙伏诛指日可待。我姐姐近
期已潜至万马堂左近，你可速与她接洽。”\n",ob);
			tell_object(me,CYN"沈三娘俯身在你耳边说：“你可在万马堂东北侧牧草茂盛处找到姐姐藏身
之处。\n"NOR);
			me->delete_temp("marks/wanma/answer_shen");
			me->set("marks/wanma/寻地洞",1);
			return 1;	
		}
		if(arg=="no"){
			message_vision("\n$N赶紧摇了摇头说：“在下武艺低微，你还是另请高明吧。”\n"NOR,me);
			message_vision(CYN"沈三娘黯然道：“你想追随马空群的荣华富贵，我也不阻碍你。只是这个
仇我们一定会报，到时候覆巢之下，恐无完卵。若你将此事泄漏给马空群
我们也不会放过你的。”\n"NOR,ob);
			message_vision(YEL"沈三娘转过头去，用手轻轻拂去碑上的浮尘，不再看你。\n"NOR,ob);
			me->delete_temp("marks/wanma/answer_shen");
			me->set("marks/wanma/拒绝沈",1);
			return 1;
		}
		tell_object(me,"你只能回答ｙｅｓ或ｎｏ。\n");
		return 1;
	}
	return 0;
}