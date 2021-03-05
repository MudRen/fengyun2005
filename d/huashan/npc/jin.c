#include <ansi.h>
inherit NPC;
int ask_pearl();
void create()
{
 	set_name("金灵芝", ({ "jin lingzhi","jin" }) );
 	set("nickname", HIR"火凤凰"NOR );
 	set("gender", "女性" );
 	set("age", 22);
 	set("long","她直鼻梁、樱桃嘴，一双眼睛又大又亮，天上也找不出这么亮的星星。 \n" );
 	set("combat_exp", 500000);
 	
 	set_skill("unarmed", 100);
	set_skill("move", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("hanmei-force",80);
	set_skill("zhaixin-claw",60);
	set_skill("qingfeng-sword", 100);
	set_skill("anxiang-steps", 100);
	
	map_skill("force","hanmei-force");
	map_skill("unarmed","zhaixin-claw");
	map_skill("move", "anxiang-steps");
	map_skill("parry", "qingfeng-sword");
	map_skill("sword", "qingfeng-sword");
    	map_skill("dodge", "anxiang-steps");
    	
 	set("chat_chance", 1);
 	set("chat_msg", ({
 		"金灵芝大声道：偷珠子的贼，你跑到哪里我也要找到你！\n",
 		"金灵芝小声嘀咕道：其实我也不是完全来捉贼的，普天之下，什么地方我都见识过，
只有这种地方没来过，我就偏进去瞧瞧，看有谁敢把我赶出去! \n",
	}) );
 	set("attitude", "friendly");
 	set("inquiry",([
    		"珠子" : (: ask_pearl :),
    		"pearl" : (: ask_pearl :),
    	]) );
 	setup();
 	carry_object("/obj/armor/cloth", 
 		([	"name"	:	HIR "绣着金花墨凤大红箭衣"NOR,
 			"long"	:	0
 			])
 		)->wear();
 	carry_object("/obj/armor/hat", 
 		([	"name"	:	HIY "少了一粒珍珠的紫金冠"NOR,
 			"long"	:	0
 			])
 		)->wear();
	carry_object("/obj/armor/boots", 
 		([	"name"	:	HIM "粉底官靴"NOR,
 			"long"	:	0
 			])
 		)->wear();
	carry_object("/obj/armor/belt", 
 		([	"name"	:	MAG "紫金带"NOR,
 			"long"	:	0
 			])
 		)->wear();
}

void release_status(object player)
{
	
	//actually no need to delete marks, since the object will be destructed.
	//just for good habit.
	delete("marks/inaction");
	delete("marks/inask");
	if (player && present(this_object(),environment(player)))
	{
		message_vision("$N生气地喊了起来：“你真婆婆妈妈，到底跟不跟我去抓贼？你不去我自己去！”\n",this_object());
		message_vision("$N气冲冲的离开了。\n",this_object());
		destruct(this_object());
	}
	
}


int ask_pearl()
{
	object player;
	player = this_player();
	if (query("marks/inaction") || player->is_fighting(this_object()))
	{
		tell_object(player,"金灵芝现在正在忙，没空理你。\n");
		return 1;
	}
	//check if jin is in her room
	if (base_name(environment()) != this_object()->query("startroom"))
	{
		message_vision("$N一双大眼睛看着$n:“有个贼偷了我的珠子，跑进玉泉池了。”\n",this_object(),player);
		return 1;
	}
	set("marks/inaction",1);
	set("marks/inask",1);
	set ("no_arrest",1);
	message_vision("$N一双大眼睛看着$n:“有个贼偷了我的珠子，跑进玉泉池了。这位"+RANK_D->query_respect(player)+"
陪我壮壮胆，进去把他抓出来好不好？”(answer yes/no) \n",this_object(),player);
	add_action("do_answer","answer");
	call_out("release_status",30,player);
	return 1;
}

void in_bathroom(object player)
{
	object tiehua,jin/*,dingfeng*/;
	jin = this_object();
	set("chat_chance", 0);
	if (!tiehua = present("nakedman",environment(jin)))
	{
		message_vision("$N自言自语道：“看来我要找的人现在并不在。还是下次再来吧！”\n",jin);
		if (player && present(player,environment()))
		{
			message_vision("$N对$n道：这位"+RANK_D->query_respect(player)+"还是多谢你了。\n",jin,player);
		}
		message_vision("$N转身离去。\n",jin);
		destruct(jin);
		return;
	}
	message_vision("$N对$n大叫道：“你这个偷珠子的贼，还我珠子！”\n\n",jin,tiehua);
	message_vision("$N笑嘻嘻道：“姑娘真是好胆量，可惜还差一点。
姑娘若敢也跳到这水池来，才算是有胆子、有本事。”\n\n",tiehua);
	message_vision("$N的脸都气黄了，突然伸手一拉腰上束着的紫金带。\n",jin);
	carry_object("/obj/weapon/sword", 
 		([	"name"	:	MAG "紫金软剑"NOR,
 			"long"	:	"这柄剑薄而细，正是以上好的缅铁打成的软剑，平时藏在腰带里，用时迎风一抖，就伸得笔直。\n",
			"wield_msg":"只听“呛”的一声，$N手里已多了柄精光四射的$n。\n",
			"unwield_msg": "$N将手中的$n绑回腰间\n",
 		])
		);
	jin->ccommand("wield sword");
	message_vision("\n$N对$n喝道：臭贼！今日不是你死就是我活！” \n\n",jin,tiehua);
	message_vision("$N使出“清风十三式”中第八式“风动千铃”直指$n而去。
剑光点点流动，如风铃此起彼伏，却分不清到底哪一处在响！\n\n",jin,tiehua);

	//have to use call out, too many messages :(
	call_out("bathroom_actiontwo",3,player);
}

void bathroom_actiontwo(object player)
{
	object jin, dingfeng;
	jin = this_object();
	message_vision("就在这时，突见人影一闪，一个人自门外斜掠了进来!这人来得好快! \n\n",jin);
	dingfeng = new(__DIR__"dingfeng");
	dingfeng->move(environment());
	message_vision("只听“拍”的一声，$N的剑竟被他的两只手夹住! \n\n",jin);
	message_vision("$N微笑着道：“多日不见，金姑娘的剑法精进了，这一招‘柳絮飞雪’使得当真是 
神完气足，意在剑先，就连峨媚派还珠大师只怕也得认为是青出于蓝。” \n\n",dingfeng);
	if (player && present(player,environment()))
	{
		tell_object(player,"你不由疑惑道：金灵芝方才使出的明明是“清风十三式”中第八式“风动千铃”，
丁枫为何偏偏要指鹿为马呢? \n\n");
	}
	message_vision( "$N又道：“这位朋友，在下是认得的，但望金姑娘看在下薄面，放过了吧。”\n\n",dingfeng );
	message_vision("$N虽然满面怒容，但居然忍了下来。和$n一起转身就走。\n\n",jin,dingfeng);
	dingfeng->set_leader(jin);
	jin->ccommand("south");
	message_vision(YEL"$N和$n向东边荒凉的小径走去，很快消失了。\n\n"NOR,jin,dingfeng );
	delete("marks/inaction");
	//for caution, we should find that room again.
	//but jin won't be able to act in other place, let's leave it this way.
	environment()->open_path();
	destruct(dingfeng);
	destruct(jin);
}

int do_answer(string arg)
{
	object player,jin;
	player = this_player();
	jin = this_object();
	if (arg != "no" && arg != "yes")
	{
		return notify_fail("你只能回答yes/no。\n");
	}
	if (!query("marks/inask"))
	{
		return 0;
	}
	remove_call_out("release_status");
	delete("marks/inask");
	if (arg == "yes")
	{
		if ((string)player->query("gender")=="男性")
		{
			message_vision("$N呵呵笑了起来：“小姑娘胆子不小啊，什么地方都敢去。好！我 
就陪你进去抓贼。”\n",player);
		}else
		{
			message_vision("$N红着脸，偷偷笑了起来：反正那里面也没见识过。。。 
$N说：“好！我们进去抓贼！”\n ",player);
		}
		player->ccommand("follow jin");
		jin->ccommand("north");
		message_vision("$N一双大眼睛转来转去，水池里的每个男人都被她瞪得头皮发痒。\n",jin);
		call_out("in_bathroom",3,player);
		return 1;
	}
	if (arg == "no")
	{
		if ((string)player->query("gender")=="男性")
		{
			message_vision("$N对$n呵呵笑了起来：“小姑娘胆子不小啊。可男人的澡堂可不 
是你去的地方。” \n",player,jin);
		}else
		{
			message_vision("$N看看$n，心想：这小丫头疯了。 
$N说：“男人的澡堂，女孩子怎么能进去呢？” \n",player,jin);
		}
		message_vision("$n生气地瞪了$N一眼，转过头不不理$N了。 \n",player,jin);
		delete("marks/inaction");
		delete("no_arrest");
		return 1;
	}
}

int return_home(object home)
{
	//if jin is in action, don't make her returning home
	if (query("marks/inaction"))
	{
		return 1;
	}
	::return_home(home);

}