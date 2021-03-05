#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int do_story();
int do_cure();

int annie_drug()
{
	object me = this_player();

	if (me->query_temp("annie/find_herb/普生") && me->query_temp("annie/find_herb/百里灵") && me->query_temp("annie/find_herb/万小春") && me->query_temp("annie/find_herb/万春流") && me->query_temp("annie/find_herb/百里雪") && me->query_temp("annie/find_herb/叶星士")	)
	{
		message_vision(query("name")+"疑道：大家都不知道？那……那……\n",me);
		message_vision(query("name")+"突地一拍头笑道：你看我这记性，怎的忘了梅大先生？\n",me);
		return 1;
	}


	if (me->query_temp("annie/find_herb/万春流"))
	{
		message_vision(query("name")+"摇头道：我委实不记得了。\n",me);
		return 1;
	}
	message_vision(query("name")+"念念道：明烟草，明烟草．．．\n",me);
	message_vision(query("name")+"苦思良久，叹道：老朽年幼时当听人说过这味药材，只是如今什么都不记得了。\n",me);
	message_vision(query("name")+"说道：百里家久营药业，现下风云城中就有他们店铺，你且过去打听打听。\n",me);

	me->set_temp("annie/find_herb/万春流",1);
	return 1;
}


void create()
{
	
	set_name("万春流",({"wan chunliu","chunliu","wan"}));
    set("nickname",HIG"神医"NOR);
	set("long", "
此人便是名震江湖的“妙手回春“神医万春流，据说只要患者还有一
口气在，他就能药到病除。\n");

	set("age",45);
	set("attitude", "friendly");
	set("combat_exp", 5500000);
	set("skill_public",1);		
	set("inquiry", ([
        	"明烟草" : 	(: annie_drug :),
        	"人心叵测":	(: do_story :),
        	"重任":		(: do_story :),
        	"治好":		(: do_cure :),
   	]));
	
	set("chat_chance", 1);
    set("chat_msg", ({
        	"万春流低头沉思，好像浑没有意识到你的存在。\n",
     }) );
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        	(: auto_smart_fight(40) :),    
    }) );
	set_skill("prescription",200);
	setup();
	auto_npc_setup("guardian",200,190,0,"/obj/weapon/","fighter_u","herb",1);
	carry_object("/obj/armor/cloth")->wear();
		
}

int recognize_apprentice(object ob)
{
        if (!REWARD_D->check_m_success(ob,"小村神医") && !ob->query("free_learn/prescription"))
        {
                message_vision("万春流摇摇头道：你心不诚。\n\n",ob);
                return 0;
        }
    	ob->set("free_learn/prescription",1);	// some ppl didn't get this mark before the learning is implemented
    	return 1;
}

int prevent_shown(object me, string skill)
{
	if ( skill == "prescription")
		return 0;
	
	return 1;
}

int prevent_learn(object me, string skill)
{
  if (skill != "prescription")
  {
      command("shake");
      command("say 老夫只教你救人，可不教你杀人。");
      return 1;
  }
  return 0;
}


int do_story(){
	
	object me;
	me=this_player();
	
	if (REWARD_D->riddle_check(me,"小村神医")<2 
			&& !REWARD_D->check_m_success(me,"小村神医")) {
		command("say 小老儿只管治病救人，其他的，管不了，也不想管。");
		return 1;
	}
	
	tell_object(me, CYN"
万春流看了看你，沉吟片刻道：萍姑已经把黑蜘蛛的事儿都告诉我了，这事儿说来话长，
自燕南天大侠复出之后，原来恶人谷的人死的死、散的散，留下来的也都做起了本分的
买卖，这地方慢慢的没有人再提起。

去年三月间，十大恶人忽然回来了好多，哈哈儿、欧阳兄弟、轩辕三光。。开起了酒楼
饭馆，哈哈儿还捐资造了个燕大侠的铁像，说是要洗心革面，感谢燕大侠的再造之恩。

然而这谷中从此也多了许多陌生的人，他们大多行色匆匆，住一个晚上就没了踪影，运
来的货物也莫名其妙的消失了。我年纪大了，眼神不好，心思可不笨，这里面一定有名
堂。所以我让萍姑找了黑蜘蛛在暗中察看，没想到却失手被欧阳兄弟擒住，若不是你撞
破，恐怕他早就凶多吉少了。。。。

万春流说：我这两天眼皮狂跳，莫不是这恶人谷又要腥风血雨，祸乱世间了。

万春流叹口气：我老了，帮不了你什么忙，你自己想办法吧。我就在这屋里守着，如果
你有个头痛脚痛，跌打流血的，只要能回来，我就想法替你"YEL"治好"CYN"。\n"NOR);
		
		return 1;
}


int do_cure(){
	
	object me;
	me = this_player();
	
	if (!REWARD_D->check_m_success(me,"小村神医")) {
		tell_object(me,CYN"万春流愁眉不展：咳，我这里缺了七枝一叶花，配不全药啊。\n"NOR);
		return 1;
	}
	
	if (me->query_temp("marks/eren/in_cure")){
		tell_object(me,"万春流说：好好静心休息，别东问西问的了。\n");
		return 1;
	}
	
	if (me->query("eff_kee")>= me->query("max_kee")
		&& me->query("eff_sen")>=me->query("max_sen")
		&& me->query("eff_gin")>= me->query("max_gin")){
		command("say 你好象没受什么伤啊！");
		return 1;
	}	
		
	message_vision(CYN"万春流端出一碗绿色的药汤给$N灌了下去。\n"NOR, me);
	command("say 这药性发作甚慢，你需在我房中静心休养，切记不可离开，否则有生命之忧！\n\n");
	tell_object(me,YEL"你觉得药性辛辣，一股炙热之气从两侧经脉中注入。\n"NOR);
	me->set_temp("marks/eren/in_cure");
	environment()->do_recover(me, 0);
	return 1;	
}
	

int accept_object(object me, object obj){
	
	if (obj->query("name") != "七枝一叶花"
			|| !obj->query("wanchunliu")) 
		return 0;
		
	command("smile");
	command("nod");
	command("say 好，有了这七枝一叶花，寻常的伤病就一定能"YEL"治好"CYN"了。");
	command("say 你心意纯朴，我可传授你一些医疗之道，救人自救都有好处。");
	REWARD_D->riddle_done(me,"小村神医",20,1);
	me->set("free_learn/prescription",1);
	return 1;
}
		