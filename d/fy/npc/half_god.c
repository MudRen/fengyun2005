inherit NPC;
#include <ansi.h>
inherit F_MASTER;

int s_quest();
int give_reward(object who,mapping quest);
int time_period(int timep, object me);
int wait_period(int timep, object me);
int newbie_quest();
string sysmsg;

void create() {

    set_name(HIY"天机老人"NOR, ({ "tian ji","tianji"}) );
    set("gender", "男性");
    set("long", "
天机老人年过六甲，鹤发童颜。在兵器谱上排名第一，尤在上官，小李
之上．此人亦正亦邪，凡事都由爱恶而定。。。。\n");
	set("attitude", "peaceful");
	create_family("潇遥派", 1, "祖师");
	set("title", "闲云野鹤");
	set("class","tianji");
	
	set("age", 99);
	set("str", 2600);
	set("NO_KILL",1);
	
	set("inquiry",	([
		"汇报":		(: s_quest() :),
		"回报":		(: s_quest() :),
	]));
		
	set("chat_chance", 1);
	set("chat_msg", ({ 
		"天机老人拿起旱烟抽了几口。。。。\n"
	}));
	
	set("combat_exp", 20000000);
	set("score", 200000);
	
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("iron-cloth", 200);
	set_skill("yiqiforce", 300);
	set_skill("dagger",200);
	
	map_skill("iron-cloth", "yiqiforce");
	map_skill("force", "yiqiforce");
	map_skill("unarmed", "yiqiforce");
	
	
	setup();
	carry_object(__DIR__"obj/jade-cloth")->wear();
	carry_object(__DIR__"obj/hanyan")->wield();
}

int s_quest(){
	object me = this_player();
//	object ob = this_object();
	
	if (me->is_fighting())	return notify_fail("你现在正忙。\n");
		
	if (me->query("quest/quest") == "沉萼落香"){
		if (time() - me->query("quest_time") > 290) {
			tell_object(me,"天机老人不满地说：你这个懒骨头，发呆时间太长乐。\n");
			tell_object(me,"你没有在规定的时间内完成天机老人的任务，你的任务自动取消了。\n");
			me->delete("quest");				// both are required
			me->delete("annie_quest");
			me ->delete_temp("annie_quest");		
			me->delete_temp("quest_number");
			me->delete("cont_quest");
			me->delete_temp("luyu");
			return 1;
		}
		if (time()-me->query("quest_time")< 180) {
			tell_object(me,"天机老人说：喝茶更衣伸懒腰，或者。。。。\n");
			message_vision("天机老人一挥手，$N腾云驾雾地飞了出去。\n"NOR, me);
			if (me->query("gender")=="男性")
				me->move("/d/qianjin/hotel2");
			else
				me->move("/d/fugui/kefang");
			tell_object(me,"（你还需要"+ chinese_number(me->query("quest_time")+180-time())+
				"秒钟才能完成这个任务）\n");
			return 1;
		}
		tell_object(me,"天机老人说：不错不错，劳逸结合，才能够长寿哈。\n");
		if ( QUESTS_D->verify_quest(me,"沉萼落香"))
			QUESTS_D->special_reward(me,"沉萼落香");
		return 1;
	}
	
	command("dapp " + me->query("id"));
	return 1;
}


int accept_fight(object me) {
	command("say 生命可贵！不要自寻死路！");
	return 0;
}


void init() {
	add_action("give_quest", "quest");
	add_action("q_return", "qreturn");
}


int accept_object(object who, object ob) {
	if (QUESTS_D->accept_quest_object(who, ob, this_object()))	{
		return 1;	
	}
	else
	{	
			tell_object(who, "天机老人笑嘻嘻地说：想孝敬爷爷就多给爷爷干活！\n");
			return 0;
	}
}

int q_return(string arg){
	object me,box;
	mapping quest,items;
	string name,*dir;
	int num, index, i;
	
	me = this_player();

	if (!(box = present("treasure box", me)))
		return notify_fail("此命令只有携带玄灵玉盒的人才能使用。\n");
	
	if (!box->query("quest_box"))
		return notify_fail("此命令只有携带玄灵玉盒的人才能使用。\n");
	
//	items = box->item_list();
	
	items = me->query_qitems();
	
	if (!items || sizeof(items)<1)
		return notify_fail("你的玄灵玉盒是空的。\n");
	
	if (arg)
		name = arg;
	else if (mapp(quest = me->query("quest")))
		name = quest["quest"];
	else
		return notify_fail("你想交还哪一个Ｑｕｅｓｔ物品？\n");
	
	if (!name)
		return notify_fail("你想交还哪一个Ｑｕｅｓｔ物品？\n");
		
	if (box->query("timer/op") + 2> time()) {
		write("为节省系统资源，玄灵玉盒命令不能连续操作，请等待２秒钟。\n");
		return 1;
	}
	box->set("timer/op", time());
	
	arg = box->replace_color(name);
	num = sizeof(items);
	dir = keys(items);
	index = member_array(arg, dir);
	if (index == -1) {		// 做一次无颜色的匹配
		for (i= 0; i<num; i++) {
			if ( arg == "/feature/nada"->ngstr(dir[i])) {
				index = i;
				break;
			}
		}
	}

	if (index==-1)
		return notify_fail("你的玄灵玉盒中没有"+arg+"这个物品。
＜格式：ｑｒｅｔｕｒｎ　中文物品名＞\n");

	if (QUESTS_D->accept_quest_object(me, dir[index], this_object())){	
		box->do_qqdiscard(dir[index],me,0);
		return 1;							
	}
	tell_object(me, "天机老人说：这个东西不是我想要的。\n");
	return 1;	
}

int give_quest(string arg) {
	
	int gold,rt,gr, level;
	object who;
	
	who = this_player();
//	这里是给刚进来的ｎｅｗｂｉｅ的ｆｉｘｅｄ　ｑｕｅｓｔ。	
	if (REWARD_D->riddle_check(this_player(),"新手入门") 
		&& !REWARD_D->check_m_success(this_player(),"新手入门")) {
		newbie_quest();
		return 1;
	}
	
	gold  = this_player()->query("deposit")/100;
	if ((arg == "cancel" || arg == "fail") && this_player()->query("quest"))
	{
			
		// 不能取消类：
		rt = this_player()->query("quest")["cancel"];
		if (rt == -1)
		{
			tell_object(this_player(),"这么重要的任务，怎么能取消呢．．．\n");
			return 1;
		}
		
		level = F_LEVEL->get_level( who->query("combat_exp"));
		
		if (level >= 80)		gr = 200;		// 4M
		else if (level >=50)	gr = 150;		// 2M
		else if (level >=30) 	gr = 100;		// 1M
		else if (level >=10)	gr = 50;		
		else 					gr = 25;
		
		if (arg == "cancel")		gr = gr*2;

/*		if (rt>0)
			gr = gr + gr*rt/100;	*/
			
		// this is for quest optimization
		if (who->query("timer/quest_cancel") + 300 > time())
		{
			who->add("marks/quest_cancel",1);
		}
		who->set("timer/quest_cancel",time());
        
        if (gold <gr)
		{
			tell_object(this_player(),"你银行里存款不够"+chinese_number(gr)+"两银子。\n");
			return 1;
		}
        
        who->add("deposit", -gr*100);
        
        if ( arg == "cancel")
        {
        	tell_object(who, YEL"天机老人掂了掂手里的"+chinese_number(gr)+"两银子乐呵呵地说：既然不想做这个就换一个吧。
（你现在账面上还有"+chinese_number(gold-gr)+"两银子）\n"NOR);
		}	
		else
		{
			//等了小于12分钟，quest fail以后还要等3分钟才能要任务 
			if (time() - who->query("quest_time") < 720){
				who->set("next_time", time() + 180);
				tell_object(who, YEL"天机老人皱着眉头说：我也不强人所难，扣你"
				+ chinese_number(gr) +"两锭银，去休息休息再来领新任务吧。
				（你现在账面上还有"+chinese_number(gold-gr)+"两银子）\n"NOR);
			} else 
			//等了大于12分钟，quest fail也直接取消，不需要再等3分钟
				tell_object(who, YEL"天机老人皱着眉头说：这点事都办不好，不过看在你等了这么久，
又孝敬我" + chinese_number(gr) +"两银子的份上，给你换个任务吧。
（你现在账面上还有"+chinese_number(gold-gr)+"两银子）\n"NOR);
		}		
		who->delete("quest");				// both are required
		who->delete("annie_quest");	
		who->delete_temp("annie_quest");	
		who->delete_temp("luyu");
		who->delete_temp("quest_number");
		who->delete("cont_quest");
		return 1;
	}
	
	return QUESTS_D->give_quest(this_player(), 
			([	"name" : this_object()->name(),
                                "employer" : "天机老人" ])
			);	
}


void attempt_apprentice(object me) {
	switch(random(4)) {
		case 0:
			message_vision("$N对$n笑问道：什么是『心剑』？\n", this_object(),me);
			break;
		case 1:
			message_vision("$N对$n笑问道：什么是『敌不动，我不动；敌一动，我先动？』\n", this_object(),me);	
			break;
		case 2:
			message_vision("$N对$n笑问道：『有形，无形』是什么？\n", this_object(),me);		
			break;
		case 3:
			message_vision("$N对$n笑问道：武学的最高境界是什么？\n", this_object(),me);
			break;
	}
}

int attack()
{
	object opponent;
	opponent = select_opponent();
	if (userp(opponent)) {
		if (random(10)) {
			set_temp("last_opponent", opponent);
			command("say 生命可贵，不要自寻死路。");
			this_object()->remove_all_killer();
			return 1;
		} else {
			command("say 不知死活的东西，去死吧。");
			COMBAT_D->do_attack(this_object(), opponent, query_temp("weapon"));
			return 1;
		}
	} else if(objectp(opponent)) {
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
	
}

void unconcious()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ;

}

void die()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ;

}

///	newbie 导游ｑｕｅｓｔ　ｆｏｒ　４．１。

int newbie_quest() {

	object me,ob,silver;
	
	me=this_player();
	ob=this_object();
	
	switch (me->query_temp("marks/newbie_quest")){
		case 1: tell_object(me,WHT"
天机老人说：“你去拜见过石雁了么？出风云东城门到赤峰路，向南就是武当山。”\n\n"NOR);
			return 1;
		case 2: if (me->query_skill("literate",1) < 1) {
				tell_object(me,WHT"
天机老人说：“要学武大字不识怎么行？到北城及第街贡院王仁德那儿去
学点再来找我吧（learn literate from kao guan with 1）\n"NOR);
			return 1;
			}  		
			break;
		case 3: tell_object(me,WHT"
天机老人说：“你去拜见过塔祝了么？他在关外的大昭寺。”\n\n"NOR); 
			return 1;
		default:
	}

	if (REWARD_D->riddle_check(me,"新手入门")==4)
	{
		tell_object(me,WHT"
天机老人说：聚沙成塔，积腋成裘，功夫就是这么一点点练成的。关外走
一趟，你应该明白熟悉地图是非常重要的，所以在练功之余，要做个有心
人，多看看，多走走，具体的地图可以"HIR"ｈｅｌｐ　ｍａｐｓ"NOR+WHT"

风云里要学的东西太多了，一时半会儿我也很难说得面面俱到，好在这些
在ｈｅｌｐ文件里都有详细说明。

天机老人拍拍你的头说：风云里的师傅很多，个个都有自己的看家功夫，
去找一个适合你的吧。如果一时还不想拜师，东城金狮镖局的查猛是个很
不错的人，只要替他"HIG"出力"NOR+WHT"，他就会让你学点功夫，他那两下子，对新手是
很有帮助的，而且也不费什么力气就能学。

东城的镇风兵器铺可以买些兵器。
南城风云布铺里老裁缝那儿有些奇奇怪怪的好衣服。
西城的千银当铺和南宫钱庄是买卖东西和存钱的地方。
北城读千里的警世书局专门出售给新手的武功入门书籍。
如果受伤了可以到千金楼左右两侧的澡堂子里去洗澡，多洗洗就可以恢复。

在我这儿可以继续领任务（Quest），如果实在完不成也没关系，可以放弃
（Quest fail，等待3分钟）或者取消任务（Quest cancel，无需等待），
当然，我也会从你账户上扣点手续费。

如果有的ｑｕｅｓｔ不知道怎么完成，可以输入ｈｅｌｐ　ｑｕｅｓｔ命
令，而后选择相应的地区，里面有详细的介绍，或者可以在ｃｈａｔ和
ｎｅｗ频道上询问，风云里的热心人还是很多的。

要做ｑｕｅｓｔ，记得到西城鹦鹉阁去领一个"HIR"玄灵玉盒"NOR+WHT"，这个可是风云的
一宝啊，到那儿看看你就知道是什么了。（从广场　w w n 便到了）

这里是一两银子，你拿着上路吧。师傅领进门，修行在自身！在江湖上要
广交朋友，除恶扬善。以你的资质，日后必成大器！

"NOR);
		silver = new("/obj/money/coin_lock");
		silver->set_amount(1);	
		if (!silver->move(me))
			destruct(silver);
		
		REWARD_D->riddle_done(me,"新手入门",200,1);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"新手入门")==3)
	{	
		tell_object(me,WHT"
天机老人又说：“现在你去拜见一下关外大昭寺宝塔的塔祝，别看他不是
什么武林名人，这儿的高手们每个都到他那儿去喝过茶。。。。
到关外可以从沉香镇走，或者到西城风云驿站王凤处租马车穿越沙漠，车
费我已经替你付了。”\n"NOR);
		me->set_temp("marks/wangfeng",1);
		me->set_temp("marks/newbie_quest",3);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"新手入门")==2)
	{		
		tell_object(me,WHT"
天机老人拍了拍你的头说：“好！好！乖孙儿，多多给我老人家干活儿就
能提高江湖历练，师傅才会教你功夫。不过，要学武功不识字可不行。。。。\n"NOR);
		if (me->query_skill("literate",1)>=1) {
			tell_object(me,WHT"\n你学到了读书识字，你的江湖历练丰富了！\n"NOR);
			me->add("combat_exp",500);
			tell_object(me,YEL"
嗯，看来三字经你已经有点心得了，及第街读千里那儿还有许多打基础的
书籍，有空可以去钻研一下。记住，书读得越多，人就越聪明，学武功，
读秘籍就能事半功倍。（使用命令skills可以查看你自己学过的技能）

天机老人又说：“现在你去拜见一下关外大昭寺宝塔的塔祝，别看他不是
什么武林名人，这儿的高手们每个都到他那儿去喝过茶．．．
到关外可以自此向南从沉香镇走，或者到西城风云驿站王风处租马车穿越
沙漠，车费我已经替你付了。”
（风云的地方很大，如果你是新来乍到，记得随时使用ｍａｐ指令，同时
也可以参看help newbie中的风云地区篇来得到一些提示。）\n"NOR);
			me->set_temp("marks/wangfeng",1);
			REWARD_D->riddle_set(me,"新手入门",3);
			me->set_temp("marks/newbie_quest",3);
			return 1;
		} else {
			tell_object(me,WHT"
北城贡院里的考官王仁德正在传授三字经，你去学一点儿再回来见我：
learn literate from kao guan with 1\n\n"NOR);
			me->set_temp("marks/newbie_quest",2);
			return 1;
		}
	}

	
	if (REWARD_D->riddle_check(me,"新手入门")==1)
	{
		tell_object(me,WHT"
天机老人和善地看着你说：“是第一次到风云城吧，小小年纪就能出来闯
荡江湖了，有志气！这风云说难也不难，你别看现在那些老家伙们牛气烘
烘，俗话说长江后浪推前浪，前浪死在沙滩上，只要你肯下苦功，有朝一
日砍他们就像砍瓜切菜一样．．．．”

天机老人说：“夫天将降大任于斯人也，必先苦其筋骨，劳其心志，不过，
万事开头难，想成为高手，就要从小事做起 ---- 也就是给我老人家跑跑
腿儿。这样吧，我好久没见到武当石雁真人了，替我去向他问个好。出风
云东城门到赤峰路向南，上了武当山就能找到他。”\n\n"NOR);
		me->set_temp("marks/newbie_quest",1);
		return 1;
	}
	return 1;
}

//
//void reset(){
//	if (environment())
//		command("chat [1;31m风起云涌，天地变色，万物复苏，英雄辈出。[0;32m");
//}
