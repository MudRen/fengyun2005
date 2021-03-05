inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int	story1();
void	leg_bye();

void create()
{
        set_name("蓝一尘", ({ "master yichen", "master", "master lan" }) );
        set("nickname", HIC "神眼神剑"NOR);
        set("gender", "男性" );
        set("long","
这个人头戴着顶宽边竹签，戴得很低，不但盖住了眉毛挡住了眼睛，连
一张脸都隐藏在竹笠的阴影里，只能看到他的一双手。他的手掌很宽，
手指却很长，长而瘦，指甲剪得很短，手洗得很干净。他身上穿着件已
经洗得发白的蓝裁护衫，洗得非常非常干净，背后还背着柄装在小牛皮
剑鞘里的长剑，比平常人用的剑最少长七八寸。剑鞘已经很破旧，剑柄
上却缠着崭新的蓝绫，用黄铜打成的剑锷和剑鞘的吞口也擦得很亮。 \n");

        set("reward_npc", 1);
	set("difficulty", 10);
		
        set("age", 54);
        set("skill_public",1);
	
	set("attitude","friendly");
        
        set("combat_exp", 6000000);
        set("score", 200000);
                
        set("chat_chance", 1);
        set("chat_msg", ({
                "蓝一尘神色凝重望着密林深处，一字字道：大好男儿，当浴血锄奸，慨然踏死。\n",
        }) );

	set("inquiry", ([
                "莲姑" : 	"莲姑是镇上老于头的女儿。\n",
                "lian gu" :  	"莲姑是镇上老于头的女儿。\n",
                "杨铮" : 	"杨铮乃故人杨恨之子，据说他正在调查一桩重案。\n",
                "yang" : 	"杨铮乃故人杨恨之子，据说他正在调查一桩重案。\n",
                "yang zheng" : 	"杨铮乃故人杨恨之子，据说他正在调查一桩重案。\n",
                "吕素文":	"吕素文乃杨铮之妻，奇女子啊！！\n",
                "lu suwen":	"吕素文乃杨铮之妻，奇女子啊！！\n",
                "重案":		(: story1() :),
                "镖银":		(: story1() :),
                "镖银失窃":	(: story1() :),
                "案情":		(: story1() :),
                "正月初三":	"青龙会属下有三百六十五个分舵，“正月初三”就代表它属下的一个分舵的舵主",
                "di qinglin" :  "你说的可是视功名富贵如尘土、却把名马美人视如生命的狄小侯爷狄青麟！\n",
                "狄青麟" : 	"你说的可是视功名富贵如尘土、却把名马美人视如生命的狄小侯爷狄青麟！\n",
                "青龙会":	"青龙会是一个极庞大的秘密组织，四百年来，江湖中从来未有过比
青龙会更庞大严密的组织。 \n",
        ]));
        
        create_family("蓝山剑宗", 3, "宗主");
        	
	set("chat_chance_combat", 5);
    	set("chat_msg_combat", ({
	     (: leg_bye() :),
        }) ); 	
	
        set_skill("move", 120);
	set_skill("parry", 120);
        set_skill("dodge", 120);
	set_skill("sword", 150);
	set_skill("unarmed",120);
	set_skill("sky-steps",100);
	set_skill("whip",150);
	set_skill("xiaohun-sword",150);
	set_skill("xiaohun-whip",150);
		
	map_skill("dodge", "sky-steps");
	map_skill("sword", "xiaohun-sword");
	map_skill("parry", "xiaohun-sword");
	map_skill("whip","xiaohun-whip");

        setup();
        carry_object(__DIR__"obj/bluesword")->wield();
        carry_object(__DIR__"obj/shirt")->wear();
		add_temp("apply/damage",80);
}

void attempt_apprentice(object me)
{
	command("shake "+me->query("id"));

}
 
int accept_object(object who, object ob)
{
	if (is_fighting() || query_temp("in_talk"))
		return notify_fail("蓝一尘正忙，没空理你。\n");
	
	if(ob->query("name") == "给蓝一尘的信" ) 
	{
		if(ob->query("送信人")==who)
		{
    			message_vision(HIY "
蓝一尘哦了一声，拆开信来，阅罢喟然长叹，“杨铮啊杨铮，果是杨恨之子！！”

稍倾，向$N点了点头，道：“信中之事，某日后自有交待，阁下实为信人，如不
嫌弃，将来某或可传你我所学。不过现下还有件事情想请阁下代劳。密林木屋乃杨铮
亡父故居。杨铮发妻已独守三日未出，你可购些饭菜送去。”\n"NOR,this_player());
			who->set_temp("libie/离别钩_送信成功",1);
			return 1;
		}
		else
		{
    			say(HIR"蓝一尘冷冷的说：你这个家伙想以假信骗我，却也没那么容易。\n"NOR);
			return 1;
		}
	}
			
	if (ob->query("real_leavehook") && ob->query("hook_owner")== who)
	{ 
		if (REWARD_D->riddle_check(who,"离别")==3 && !ob->query("blood"))
		{
			message_vision(HIG"
蓝一尘的眼中忽然透出奇怪的炽热的光芒，

“拔你的剑！”

话音乍落，只听“呛”的一声龙吟，蓝山古剑已出鞘，森森剑气立刻弥漫了丛林。\n\n\n"NOR, who);
			full_me();
			fight_ob(who);
			who->fight_ob(this_object());
			who->set_temp("libie/fight_lan",1);
		} else
		{
			message_vision(CYN"蓝一尘的眼中忽然透出奇怪的炽热的光芒。\n"NOR, who);
		}
	}	
	return 0;
}

int recognize_apprentice(object ob)
{
	if(REWARD_D->check_m_success(ob, "离别"))
		return 1;
}

int prevent_shown(object me, string skill)
{
	if (REWARD_D->check_m_success(me,"销魂传人"))	return 0;
		
	if(REWARD_D->check_m_success(me, "离别") && skill!="xiaohun-sword")
		return 0;
		
	return 1;
}


int	story1()
{
	
	object me= this_player();
	
	if (!REWARD_D->riddle_check(me,"离别"))
	{
		message_vision(CYN"
蓝一尘说：你是何人？为何打听此事，难道是奸细不成！！\n"NOR,me);
		command("stare");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"离别")==4)
	{
		message_vision(CYN"
蓝一尘说：案情大白，狄青麟那厮乃罪有应得！！\n"NOR, me);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"离别")==3)
	{
		message_vision(CYN"
蓝一尘说：杨铮必已处在天大危险之中，你需速去助他。\n"NOR, me);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"离别")==2)
	{
		if (!me->query_temp("libie/di_1") && !me->query_temp("libie/di_2"))
		{
			message_vision(CYN"
蓝一尘说：此地有我看护，你速速查清镖银一案真相，方能洗清杨铮冤屈！\n"NOR, me);
			return 1;
		}
		if (!me->query_temp("libie/di_2"))
		{
			message_vision(CYN"
蓝一尘叹口气说：可怜的莲姑，但是就凭小叶子是狄青麟的书童这一证据，
恐怕还扳不到这个世袭一等侯，还有什么线索么？\n"NOR, me);
			return 1;
		}
		if (!me->query_temp("libie/di_1"))
		{
			message_vision(CYN"
蓝一尘沉思道：原来这里面有这么大的阴谋，但是就凭他同伙的几句话，恐
怕还扳不到这个世袭一等侯，还有什么线索么？\n"NOR, me);
			return 1;
		}
	
		message_vision(CYN"
蓝一尘怒道：原来如此，气杀我也！任他狄青麟是公子王孙，我蓝一尘手中
之剑也决计放不过他！待我处理了这儿的青龙妖孽，定去会他！

蓝一尘沉吟片刻又道：既是如此，杨铮必已处在天大危险之中，你需速去助他。\n"NOR,me);
		REWARD_D->riddle_set(me,"离别",3);
		return 1;
	}
				
	message_vision(CYN"
蓝一尘说：三日前，倪八太爷率人劫了中原镖局的一百八十万两镖银，这儿的捕头
杨铮带弟兄追杀倪八太爷，夺回了镖银。谁知螳螂捕蝉，黄雀在后，镖银还未运回
便连着两个押运的衙役一起神秘失踪，而当事人杨铮反而成了最大的疑犯。此事惊
动了朝廷，连世袭一等侯狄青麟都赶赴此地。正在这节骨眼儿上，杨铮恰恰又不告
而别，不知去向。。。。

蓝一尘握紧剑柄说：杨铮绝非见财起意之辈，但若是不把此事查个水落石出，他的
冤名决计无法洗脱，而真正的凶手为杀人灭口，也不会让他再活着。

蓝一尘叹了口气说：我本当勘查此案，但杨铮之妻在此，今日已有数批杀手前来，
而且像是青龙会的人，我需在此守卫，这、这、这可如何是好？

蓝一尘用希望的眼光看了看你道：若阁下能代我查清此案，洗清杨铮冤名，在下当
倾囊以授，感激不尽！！！

"NOR, this_object());
	REWARD_D->riddle_set(this_player(),"离别",2);
	return 1;
}


string *event1_msg=	({
	YEL"
这种手法绝不能算处什么高明的手法，在离别钩复杂奥妙奇诡的变化中，绝没有
这种变化。可是身经百战的蓝大先生这一次却好象有点乱了，竟没有出手反击，
却以“旱地拔葱”的身法，硬生生将自己的身子凌空拔起。 \n"NOR,
	
	YEL"
他本来完全没有跃起准备的，所以这一口气提上来时就难免慢了一点，虽然相差
最多也只不过在一刹那间，这一刹那间却已是致命的一刹那。\n"NOR,

 	YEL"
冰冷的钩锋已钩往了蓝一尘的腿。 
他知道他的腿已将与他的身子离别了，永远离别。 
"HIR"鲜血飞溅，血光封住了$N的眼。"NOR YEL" 
等$N再睁开眼时，蓝一尘已倒在树下，惨白的脸上全无血色，一条腿已齐膝而断。\n"NOR,

    	
});


void event1(object ob, object me, int count)
{
	if (environment(me)!=environment(ob) || ob->is_fighting()) {
		delete_temp("in_talk");
		return;
	}
	
	message_vision(event1_msg[count]+"\n",me);
	
	if(++count==sizeof(event1_msg))
	{
		message_vision(CYN"

蓝一尘只淡淡地说了一句：好，你可速将此钩交于杨铮。\n\n"NOR,me);
		delete_temp("in_talk");
		if (ob->query("eff_kee")>ob->query("max_kee")/4)
		{
			ob->set("eff_kee",ob->query("max_kee")/4);
			ob->set("kee",ob->query("max_kee")/4);
		}
		me->stop_busy();
		return;
	}
	else call_out("event1",2,ob, me,count);
	return ;
}

void leg_bye()
{
	object *enemy,me,weapon;
	enemy = this_object()->query_enemy();
	if (sizeof(enemy)>1)	return;
	
	me= enemy[0];
	
//	message_vision("enmey is "+ me->query("id")+"\n",this_object());
		
	if (REWARD_D->riddle_check(me,"离别")!=3
		|| !me->query_temp("libie/fight_lan")
		|| !(weapon = me->query_temp("weapon")))
		return;
	
	if (!weapon->query("real_leavehook") || weapon->query("blood"))
		return;
	
	if (query("kee")<0 || me->query("kee")<0 )return;
	
	weapon->set("blood",1);
	me->remove_all_killer();
	remove_all_killer();
	me->start_busy(40);
	set_temp("in_talk",1);
	message_vision(YEL"$N的钩忽然用一种丝毫不怪异的手法，从一个任何人都能想得到的部位刺了出去。
$N的钩刺出去时，$N的人也扑了过去。\n"NOR,me);
	call_out("event1",1,this_object(),me,0);
	return;
}

void	win_enemy(object me)
{
	message_vision("蓝一尘长叹一声说：凭你的武功，此行只是白白送死！\n", me);
	return;
}


void	lose_enemy(object me)
{
	message_vision("蓝一尘长叹一声，摇摇头默然无语。\n", me);
	return;
}


int prevent_learn(object me, string skill){
	if(REWARD_D->check_m_success(me, "离别"))
		return 0;
}