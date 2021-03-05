#include <ansi.h>
inherit NPC;
void dreamsay();
void create()
{
	set_name("吕素文", ({ "lu suwen","lu" }) );
	set("gender", "女性" );
	set("age", 22);
	set("str", 100);
	set("per", 50);
	
	set("inquiry", ([
                "莲姑" : 	"莲姑是镇上老于头的女儿。\n",
                "lian gu" :  	"莲姑是镇上老于头的女儿。\n",
                "杨铮" : 	"杨铮乃外子，正在调查一桩重案。\n",
                "yang" : 	"杨铮乃外子，正在调查一桩重案。\n",
                "yang zheng" : 	"杨铮乃外子，正在调查一桩重案。\n",
                "青龙会":	"青龙会是一个极庞大的秘密组织，四百年来，江湖中从来未有过比
青龙会更庞大严密的组织。 \n",
        ]));
	set("long", @LONG
一身素衣，打点的干干净净，无情的岁月在一张本是清秀动人的面庞上
留下了些许苍老与疲倦。
LONG
);	set("combat_exp", 10000);
	set("attitude", "friendly");

	setup();
	this_object()->disable_player( HIG "<睡梦中>"NOR);
//	this_object()->set_temp("is_unconcious",1);
//	set_temp("block_msg/all", 1);
//	COMBAT_D->announce(this_object(), "unconcious");

	carry_object(__DIR__"obj/white_cloth")->wear();
}

int accept_fight(object me)
{
	command("emote 睡得正香，一点反应都没有。");
	return 0;
}


void init()
{
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_answer","answer");	
	if(!living(this_object()))
	if(!query("开始说梦话"))
	{
		set("开始说梦话",1);
        	call_out("dreamsay",10+random(100));
	}
	::init();
}

void dreamsay()

{	object room;

	if(!living(this_object()) &&this_object()->query("disable_type")==HIG"<睡梦中>"NOR)
	{
		room=environment(this_object());
                message("vision","吕素文翻过身，长长的睫毛闪着幸福的泪光，睡梦中喃喃道：杨铮哦，你回来了，\n饭菜凉了。。。我这就去热。。\n",room);
		call_out("dreamsay",10+random(100));
	}
	else
		delete("开始说梦话");
	return;
}

void heart_beat()
{
	int msg;
	object me,lu,sheet;
	

	if(!living(this_object())&&this_object()->query("disable_type")==HIG"<睡梦中>"NOR)
	if(!query("开始说梦话"))
	{
		set("开始说梦话",1);
		call_out("dreamsay",10+random(10));
	}
	if(msg=query("dying_msg"))
	{
		me=environment()->query("结局1人物");
		lu=this_object();
		if(msg==4)
            		message_vision(YEL"$N平静地问：我夫君是不是已经不在人世了？\n"NOR,lu);
		if(msg==3)
			me->ccommand("hmm");
		if(msg==2)
            		message_vision(YEL"\n$N眼神变得迷离，口中轻呓道：杨郎。。。我来了。。\n
吕素文的声音越来越微弱。。。\n"NOR,lu);
		if(msg==1)
		{
            message_vision(HIG"\n$N似又睡着了，疲倦的脸上露出安详的微笑。。。
微风在轻轻叹息，窗外飞过的雀儿在低低啁啾，一切归于宁寂。。。\n\n\n"NOR,lu);
			sheet = new(__DIR__"obj/sheet");
			sheet->move(environment(this_object()));
			REWARD_D->riddle_done(me,"离别",200,1);
			me->delete("libie");
			me->delete_temp("libie");	// 清除所有挖坑以外的mark，允许重做但是奖励就是第一次的
			me->set_temp("libie/离别钩_尾声",1);	// 如果不抓紧就重头来了
			lu->die();
		}
		add("dying_msg",-1);
	}
	::heart_beat();
}

void sleep()
{
	message("vision","吕素文打了个呵欠，重新睡了过去。\n",environment());
	this_object()->set_temp("is_unconcious",1);
	this_object()->disable_player(HIG "<睡梦中>"NOR);
}

void wake(object me)
{	string msg;
	object room;
		
	this_object()->delete_temp("is_unconcious");
	this_object()->enable_player();
	room=environment();
	if (present(me->query("id"),room)) 
		message_vision(HIG"吕素文睁开双眸，惊呼一声。盯着$N。\n"NOR,me);
	else 
		message("vision",HIG"吕素文睁开双眸，惊呼一声。\n"NOR,room);

}

int dying(object me)
{
	set("dying_msg",4);
	heart_beat();
	return 1;
}

void die()
{	object me,corpse,*inv,room;
	int i;

	room=environment();
	if(me=room->query("结局1人物"))
		me->delete_temp("libie/离别钩_目睹最后结局");
	corpse=new("/d/libie/obj/lucorpse");
	corpse->move(room);
	message_vision("吕素文死了。\n",this_object());
	destruct(this_object());
		
}


int ask_question(object me)
{	
	if(environment(me)!=environment()) return 0;

    	message_vision(YEL "吕素文看了眼热气滕滕的饭菜，若有所思，整了整衣襟，正色道：阁下
是蓝大侠差来送食的吧？(answer yes or no)\n"NOR,me);
	me->set_temp("libie/answer_lu_1",1);
	return 1;
}

int do_answer(string arg)
{
    	object ob, me, book;
    	ob = this_object();
    	me= this_player();
    	
    	if (!me->query_temp("libie/answer_lu_1"))	return 0;
    	
    	if (arg == "yes" || arg == "no")
    	{
    	    	me->delete_temp("libie/answer_lu_1");
    		me->delete_temp("libie/离别钩_准备送饭");
    		if( arg == "yes" )
    		{
        		if(!REWARD_D->riddle_check(me, "离别")){
        			REWARD_D->riddle_set(me, "离别",1);
        			message("vision",YEL "
吕素文微笑而坚定的说：顺请阁下告知蓝大侠，素文立过重誓，余生只
与我夫郎共饮。

吕素文轻咳几声，道：阁下若有意助我夫妇，可助我夫君破获镖银失窃
一案，凶犯归案之日，便是我夫妇团聚之时。

吕素文又道：杨郎怕我担心，不愿我多知道案情，你若有心相助，可向
蓝大侠询问，虽然他是杨郎的仇人，却也是条铮铮的汉子。

吕素文叹了口气，闭目无语。\n"NOR,me);
			} else 
				message_vision(HIY "吕素文道：贱妾心意已决，阁下请不必多言。\n"NOR,me);
    		 } else if( arg == "no" ) 
	 	       	message_vision(HIG"吕素文微叹一声，闭目不语。\n"NOR, me);
	 	return 1;
    	}
    	return 0;
}

int give_sword(object me)
{
	
	object sword,ob = this_object();
	if(environment(me)!=environment()) return 0;
	
	if (me->query_temp("libie/lu_sword"))
	{
		message_vision(YEL"吕素文看了看你的身后，失望地叹了口气。\n"NOR, me);
		return 1;
	}
	
	tell_object(me,"（你向吕素文简单交待了狄青麟和杨铮的情况。。。）\n");
	tell_object(me, YEL"
吕素文的嘴唇忽然变得冰冷而颤抖，但却还是勉强压制着自己。 
可是她的眼泪还是忍不住流了下来。

吕素文翻开地上的一块木板，从木板下的地洞里提出个生了锈的铁箱子。 
铁箱里居然有个火折子。 
吕素文打亮了火折，你就看见了一件从未见过的武器，

"WHT"一件形状怪异的兵刃，闪起了一道寒光---离别钩！"YEL"

吕素文神情黯然：“这是杨铮父亲唯一留下来的遗物，可是杨铮说，不
到生死关头，非但绝不能动用它，而且连说都不能说出来。因为这柄钩
无论钩住什么，都会造成离别。

吕素文说：请你把这柄钩交给杨铮，就说我在等他回来。

吕素文微叹一声，转入屋后。\n"NOR);

	sword = new(__DIR__"obj/leavehook");
	if (sword)	
	if (!sword->move(me))	sword->move(environment(me));
	sword->set("hook_owner",me);
	me->set_temp("libie/lu_sword",1);
	remove_call_out("sleep");
	destruct(this_object());	// At most 15 mins a sword bah :D
	return 1;
}
	


