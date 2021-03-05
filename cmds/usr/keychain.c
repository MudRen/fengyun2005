#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{

	object room,ob,coin;
	string rname,str;
	string *driddle = ({"巧入万梅","幽灵山庄","长春迷宫","七仙女阵",
		"守经楼","狼山探险","雾笼狼山","沙漠驼旅","五行铜人","勇闯蝙蝠岛","探饿虎岗","神水探幽","龙虎寨土匪"});
	string *content = ({"万梅山庄的琴声",
						"幽灵山庄的哨声",
						"长春岛的哨声",
						"大旗谷的树叶",
						"进入少林寺",
						"进入狼山前山",
						"进入狼山后山",
						"老云寨的哨声",
						"进入兴国禅寺",
						"搭乘蝙蝠岛的渡船",
						"进入饿虎岗的大门",
						"微型风筝",
						"给钱就行",
					});
	int i;
	
	seteuid(getuid());	
	if (!REWARD_D->check_m_success(me,"如意燧链"))
		return notify_fail("你还没有激活如意燧链，该物可在鹦鹉阁购买。\n");
	
	if (arg == "-coin") {
		if (me->query("deposit")< 100)
			return notify_fail("你没有足够的存款来执行此指令。\n");
		if (me->query("timer/keychain_coin")+ 300 > time())
			return notify_fail("此命令每三分钟才能执行一次。\n");
		coin = new("/obj/money/coin");
		coin->set_amount(50);
		if (!coin->move(me)){
			destruct(coin);
			return notify_fail("你携带物品过多，无法执行此指令。\n");
		}
		write(WHT"如意燧链哗哗作响，跳出五十个铜板来。\n"NOR);
		me->add("deposit",-50);
		me->set("timer/keychain_coin",time());
		return 1;
	}
	
	if (arg=="-list") {
		write(WHT"    风云地区出入的途径及对应谜题
=======================================\n\n"NOR);		
		for (i=0;i<sizeof(driddle);i++){
			str = (REWARD_D->check_m_success(me,driddle[i]))?
					CYN""+ driddle[i]+""NOR	: driddle[i];
			write(sprintf(YEL"  %-20s"NOR"%-20s\n",
				content[i],
				str,
				));
		}
		write(WHT"
=======================================\n"NOR);
		return 1;
	}		
		
	if (arg)	 
		return notify_fail("此命令不需要其他参数，会根据你所处的环境自动判断。\n");
		
	room = environment(me);
	rname = file_name(environment(me));
	
//	write(" it is "+ file_name(environment(me))+"\n");
	
	if (me->query("deposit")<100)
		return notify_fail("使用如意燧链需要至少有一定的实力（存款）\n");
	me->add("deposit",-100);	
		
	switch (rname) {
		
		case "/d/wanmei/gate":
			if (REWARD_D->check_m_success(me,"巧入万梅")) {
				message_vision("$N从身上解下古琴，信手一划，泉水般的琴声从指尖流泻而出。
漫山的梅林沙沙作响，似乎也在为你伴唱，庄内的杀气顿时消散了。\n",me);
				me->set_temp("played_qin",1);
				return 1;
			}
			break;
		case "/d/ghost/forest9":
			if (REWARD_D->check_m_success(me,"幽灵山庄")){
				message_vision("$N从身边掏出一个两寸多长的铜哨吹了一声。\n",me);
        		room->pipe_notify();
        		return 1;
        	}
        	break;
		case "/d/eastcoast/seaside":
		case "/d/eastcoast/seaside2":
		case "/d/changchun/island":
			if (REWARD_D->check_m_success(me,"长春迷宫")){
				message_vision("$N从身边掏出一个两寸多长的铜哨吹了一声。\n",me);
        		room->pipe_notify();
        		return 1;
        	}
        	break;
		case "/d/eastcoast/troad3":
			if(REWARD_D->check_m_success(me,"七仙女阵")){
				me->set_temp("mark/cat",1);
				message_vision("$N向小猫咪眨了眨眼睛，小猫咪似乎记起了$N，跑过来在$N的脚上蹭了蹭，
伸出个爪子向西边的山壁指了指又跑开了。\n",me);
				return 1;
			}
			break;
		case "/d/shaolin/ye1":
		case "/d/shaolin/ye2":
			if (REWARD_D->check_m_success(me,"守经楼")){
				message_vision("$N沉声道：在下为贵寺找还了失落的经书，众位师兄莫非不记得了么？\n",me);
				me->set_temp("shaolin",1);
				return 1;
			}
			break;
		case "/d/wolfmount/bigstage":
			if (REWARD_D->check_m_success(me,"狼山探险")){
				if(objectp(ob=present("fighter wolf",room))) {
					message_vision("$N拍了拍$n的肩说，这位兄弟，上次的野味不错吧。
$n大笑道：不错、不错、果真是家兔不如野兔香啊！\n", me, ob);
					me->set_temp("marks/狼山游客",1);
					return 1;
				}
			}
			break;
		case "/d/wolfmount/brook":
			if (REWARD_D->check_m_success(me,"雾笼狼山")){
				me->set_temp("annie/wolf_conch",1);
				message_vision("$N从身边掏出一个小海螺，嘟噜噜地吹了几声。\n",me);
				return 1;
			}
			break;
		case "/d/oldpine/keep2":
			if (REWARD_D->check_m_success(me,"沙漠驼旅")){
				message_vision("$N尖起嗓门儿，学着小土匪的声调吆喝了几声。\n",me);
				room->pipe_notify();
				return 1;
			}
			break;

		case "/d/qianfo/dadian":
			if (REWARD_D->check_m_success(me,"五行铜人")){
				message_vision("$N从身畔掏出五枚小针放入铜人中。\n",me);
				me->set_temp("marks/copperman",1);
				return 1;
			}
			break;
		case "/d/eastcoast/bfd1":
			if (REWARD_D->check_m_success(me,"勇闯蝙蝠岛")) {
				tell_object(me, "正巧，海边停着一条大船，你大喜过望，得意洋洋的走上了大海船.......\n\n" NOR ) ;
	  			message_vision("船夫一见$N上船，忙叫了一声：开船喽！\n", me);
	  			message_vision("船夫升起帆，船就向东方航行。\n\n", me);
	  			room = find_object(AREA_BAT"dahai");
	  			if (!room)	room = load_object(AREA_BAT"dahai");
	  			me->move(room);
				return 1;
			}
			break;
		case "/d/bawang/ehugang":
			if (REWARD_D->check_m_success(me,"探饿虎岗")) {
				message_vision("$N从地上抓起些黑土往脸上抹了抹，又把衣服拉了几个口子，一瘸一拐地走向两个喽罗。
大喽罗懒洋洋地说：小山东啊？上次的烧鸡不错，以后多捎几个给大爷。
小喽罗低头啃着鸡翅，不耐烦地向后面指了指。\n",me);
				me->set_temp("marks/keychain_ehg",1);
				return 1;
			}
			break;
		case "/d/laowu/baishui":
			if (REWARD_D->check_m_success(me,"神水探幽")){
				ob = new(AREA_QINGPING"npc/obj/kite");
				room->kite_notify(ob,1);
				return 1;
			}
		case "/d/zangbei/wild3":
			if (ob=present("bandit",room)){
				if (me->query("deposit")>10000) {
					message_vision("$N从腰包里掏出一张银票，满脸堆笑地递给$n\n",me,ob);
					me->add("deposit",-10000);
					if (me->query_temp("wild4_pass") || me->query("combat_exp")<1000000)
						ob->ccommand("say 这么主动？又送保路费来了？");
					me->set_temp("wild4_pass", 1);
					ob->ccommand( "say 哈哈，看在你孝顺的份上，就给你个方便吧。");
					return 1;
				} else
					message_vision("$N说：穷叫花子，没钱就去取！\n",ob);
				return 1;
			}
			break;
					
	}

	me->add("deposit",100);	// 没起作用，还钱
	
//	write ("not exec \n");
	return notify_fail("如意燧链没有什么反应，大概是地方不对，或者你没完成相应的谜题。\n");
}


int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式： keychain [-list | -coin ][0m
[0;1;37m────────────────────────────────[0m

如意燧链是风云２００５继玄灵玉盒后推出的又一项降低反复操作，
增强游戏趣味性的宝物。

风云中有许多地区需要解谜后方能进入，而每次解谜需要收集各项
物品，给一些不能长久在线的玩家带来了困难。

有了如意燧链就不用再为这个发愁了！

只要你完成了这个地区所对应的谜题，如意燧链就会将有关物品自
动收藏起来，既不占地方，也没有重量，亦不会因为你下线而消失。
等你再次上线需要进入那些地区时，只需在原来解谜的场所输入
ｋｅｙｃｈａｉｎ，如意燧链就会做出相应的反应，至于在什么地
方使用，就靠你自己琢磨了。

使用ｋｅｙｃｈａｉｎ　－ｌｉｓｔ命令可察看你的如意燧链上已
经具有的谜题物品。是否完成可从不同的颜色看出。

注１：如果一些地区已经有了永久性出入的谜题，就没有使用如意
燧链的必要，比如说快活林、富贵山庄、万马堂等等。一些可以非
常容易出入不要谜题物品的地区如意燧链也不适用。

注２：每次成功使用如意燧链命令会从你的账户里转走１两纹银，
不过，像兴国、少林、狼山、万梅等很多地方上线后只需要使用一
次便可高枕无忧，如此算来，还是大大划算的，

注３：如果使用 -coin 参数，则可从银行里得到五十个铜板，再也
不用担心困在某个迷宫里了。

[0;1;37m────────────────────────────────[0m
HELP
	);
	return 1;
}
