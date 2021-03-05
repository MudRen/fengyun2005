inherit NPC;
#include <ansi.h>

int nec_book();

void create()
{
        set_name("看风景的道姑", ({ "wandering taoist", "taoist" }) );
        set("gender", "女性");
        set("age", 32);
        set("long","一个叫可尔的道姑，着一身黑色的道袍，优哉游哉地在湖畔看风景。\n");
        set("combat_exp", 21000);
        set("score", 200);
        set("class", "taoist");
        
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5);

        set("inquiry", ([
                "三清湖": "在观里闷久了，出来散散心，三清湖是个好地方啊。\n",
                "内奸": (: nec_book :),
                "三清道宗": (: nec_book :),
        ]) );

		
		set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "invocation" :),
        }) );

        set_skill("magic", 20);
        set_skill("move", 20);
        set_skill("force", 20);
        set_skill("spells", 30);
        set_skill("unarmed", 40);
        set_skill("sword", 40);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("gouyee", 50);
        set_skill("taoism", 30);
        set_skill("necromancy", 30); 
        set_skill("snowshade-sword",30);
        set_skill("notracesnow",30);

		set("no_arrest",1);
        
        map_skill("dodge","notracesnow");   
	map_skill("force", "gouyee");
        map_skill("spells", "necromancy");
        map_skill("parry","snowshade-sword");
        map_skill("sword","snowshade-sword");

        setup();

        carry_object(__DIR__"obj/sword1")->wield();
        carry_object(__DIR__"obj/tcloth")->wear();

}


void init()
{	
	::init();
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
    	object player, victim;
    	player = this_player();
    	if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
    	if(!objectp(victim))
		return notify_fail("这里没有这个人。\n");
    	if(living(victim))
    	{
       		if(userp(victim)&& victim!=player)
        	{
            		message_vision(HIW"$N对著$n喝道：难得出来散散心，竟然被你这小子坏了心绪!\n"NOR, this_object(), player);
            		this_object()->kill_ob(player);
            		player->kill_ob(this_object());
            		player->start_busy(2);
            		return 0;
        	} 
    	}
    	return 0;
}

int nec_book()
{
	object me,who;
	int i;
	me = this_object();
	who = this_player();
	i = REWARD_D->riddle_check(who,"无字天书");
	if (!i)
	{
		message_vision(CYN"$N说道：你在说什么？我怎么听不懂？\n"NOR,me);
		return 1;
	}
	if (i != 3)
	{
		message_vision(CYN"$N默默的看着湖水，一语不发。\n"NOR,me);
		return 1;
	}
	if (present("taoist feng",environment()))
	{
		message_vision(CYN"$N抬起头看了$n一眼，欲言又止。\n"NOR,me,who);
		return 1;
	}
	who->start_busy(30);
	message_vision(CYN"$N抬起头看了$n一眼。\n"NOR,me,who);
	call_out("do_ggyy",2,me,who,0);
	return 1;
}

void setlog(object me)
{
	int a,b,c;
	int i,j,x;
	string *msg = ({
"annie/demon_puzzle_lin",
"annie/demon_puzzle_huo",
"annie/demon_puzzle_san",
});
	string *msg2 = ({
"偷书的人是萧王孙的得意门生。",
"偷书的人曾在金钱帮学艺，这你都不知道？",
"偷书的那个是丐帮出身，因此窃术出神入化。",
"偷书的人不是快鞭，快鞭是清白的。",
"毒指自然不偷书，毒指偷书做什么？",
"偷书？这种事怎么可能是傲骨峥峥的狂杖所为。",
});
	a = random(3);	
	b = random(2);
	switch (a)
	{
		case 0:
			if (b) 	{ b=1; c=2;}
			else	{ b=2; c=1;}
			break;
		case 1:
			if (b)	{ b=0; c=2;}
			else	{ b=2; c=0;}
			break;
		case 2:
			if (b)	{ b=0; c=1;}
			else	{ b=1; c=0;}
			break;
	}
	x = random(6);
	me->set(msg[a],"我们三个人中，说真话的人只有一个。");
	switch (x)
	{
	case 0:
		me->set(msg[b],"偷书的人说的是假话。");
		me->set(msg[c],msg2[random(6)]);
		me->set("annie/demon_puzzle",a+1);
		break;
	case 1:
		me->set(msg[b],"没有偷书的人不说假话。");
		me->set(msg[c],msg2[3+a]);
		me->set("annie/demon_puzzle",a+1);
				
		break;
	case 2:
		me->set(msg[b],"没有偷书的人肯定不会说真话。");
		me->set(msg[c],msg2[b]);
		me->set("annie/demon_puzzle",c+1);
		break;
	case 3:
		me->set(msg[b],"没有偷书的人肯定不会说真话。");
		me->set(msg[c],msg2[c]);
		me->set("annie/demon_puzzle",b+1);
		break;
	case 4:
		me->set(msg[b],"没有偷书的人肯定不会说真话。");
		me->set(msg[c],msg2[3+b]);
		me->set("annie/demon_puzzle",b+1);
		break;
	case 5:
		me->set(msg[b],"没有偷书的人肯定不会说真话。");
		me->set(msg[c],msg2[3+c]);
		me->set("annie/demon_puzzle",c+1);
		break;
	}
	return;
}

void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"看风景的道姑说道：你既然找到我了，我也不妨直言。",
"看风景的道姑说道：三年前一日我路过白云楼，偶然见到四位供奉争吵密议。",
"看风景的道姑说道：好奇之念让我潜下偷听，明白了事情始末。",
"看风景的道姑说道：原来是有人指使供奉其中一人，让他寻找破解后山黑洞封印之术。",
"看风景的道姑说道：他四处打探却百寻不获，一急之下就潜入白云楼，偷去了那本"YEL"三清道宗。"NOR,
"看风景的道姑说道：而书中，果然记有蚀封之术。",
"看风景的道姑说道：那人原本打算将法术抄下后偷偷送还，结果却被主子看见。",
"看风景的道姑说道：他主子见到秘籍，大喜之下就径直取走。",
"看风景的道姑说道：纸终于包不住火，他的举动很快被其他三位供奉发现。",
"看风景的道姑说道：但是他们毕竟师兄弟一场，也就互相遮掩。",
"看风景的道姑说道：——而我却在无意中踢到竹子被他们抓到，只好答应他们守口如瓶。",
"看风景的道姑说道：但他们依然不信任我，就让风道人来暗中看守。",
"看风景的道姑说道：谢谢你替我杀了风道人，我就将这个故事告诉你以为报答。",
"看风景的道姑说道：至于三清宫，我是不能再呆……言尽于此，贫尼就此告辞。\n看风景的道姑匆匆忙忙的离开了。",
});
	if (!me || !target)
		return;
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
		return;
	msg = event_msg[count];
	tell_object(target,CYN+msg+"\n"NOR);
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",1+random(2),me,target,count+1);
	else
	{
		set("ggyying",0);
		setlog(target);
		target->stop_busy();
	REWARD_D->riddle_set(target,"无字天书",4);
		destruct(this_object());
		return;
	}
	return;

}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

