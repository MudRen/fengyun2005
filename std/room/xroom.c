// 青绫的房屋函式

#include <ansi.h>
inherit ROOM;
inherit F_ANNIE;

#define DAY 86400

int save();
int restore();
int restore_item();


int is_owner(string arg)
{
	object ob;
	if (arg == query("temp_owner"))
		return 1;
	if (arg == query("owner"))
		return 1;
	
	// 增加对离婚的检查，防止一夫多妻	
	// 就是说：只有设置成2nd owner的当前伴侣才能共享
	if (arg == query("couple")) {
		ob = find_player(arg);
		if (!ob)	return 0;	
		if (ob->query("marry")!= query("owner")) {
			set("couple","出走");
			return 0;
		}
		return 1;
	}
	return 0;
}


void init()
{
	int flag;
	flag = (int) query("room_flag");
	if(flag & 1) set("valid_startroom",1);
	if(flag & 2) set("NONPC",1);
	if(flag & 4) set("no_fight",1);
    if(flag & 8) set("no_magic",1);
	if(flag & 16) set("outdoors","residence");
	if(flag & 32) set("open_area",1);

	if (!query("already_loaded"))
	{
		restore();
		restore_item();	// annie' item-save
		set("already_loaded",1);
		set("perma_exist",1);		// to help with the stack field
	}
	
	add_action("do_help","roomhelp");
	add_action("do_invite","invite");
//	add_action("do_setowner","setowner");	// 临时关闭此指令。
	add_action("do_share","share");
	add_action("do_here","here");
//	add_action("do_pay","pay");
	add_action("do_payoff","payoff");
	add_action("do_remodel", "remodel");
	add_action("do_destroy", "destroy_room");
	add_action("input_description","renovate");
	add_action("do_exercise","fight_switch");
}

// 此命令允许arch以上强制销毁房间

int do_destroy(){
	
	object me = this_player();

	if (!wizardp(me) || wiz_level(me) < 4){
		return 0;
	}	
	
	BR_D->destroy_room();
	return 1;
}


int do_help()
{
	write(@HELP   
在此房间里可执行的命令：
-Roomhelp
该命令

-Share 
与伴侣共享你的房间。只有房间的主人可以执行此指令。注意，此指
令将决定房间的第二个主人，一旦决定将无法在往后的游戏中更改。
如果今后离婚，前妻／夫仍然是第二主人，但无法再自由出入。

-Invite 
邀请其他人进入你的房间。 
只有房间的主人或第二主人可以执行此指令。 
邀请原来在名单上的人可以取消邀请。

-Here 
查看当前所在屋子的情况，任何人都可以执行此指令。

-Payoff
试图一次交清所有的余款，只有房屋的主人或第二主人可以执行此指令。
为了避免误操作，该命令要求执行者去购买一份合约。

-Remodel
将现有的房屋进行扩建，该命令唯有在已经付清现有房屋的贷款后才能
执行，为了避免误操作，该命令要求执行者去购买一份合约。扩建房屋
不再有贷款功能，必须一次付清。

-Renovate
装修现有房屋，此命令可改变屋子的描述，每次装修只耗费五两黄金，
但是每两次装修间隔时间不能少于十分钟。

HELP
    );
    return 1;
}

int query_tax()
{
//	return query("basic_tax")+query("tax");	家具暂且不收钱
	return query("total_gold")*14/15;
}

int query_stax()
{
//	return query("basic_score_tax")+query("score_tax");　家具暂且不收钱, and, using free_space is bugged here with upgrades
	int g1,old_space;
	g1 = query("total_gold");
	
	switch (g1) {
		case 150:	old_space = 1; break;
		case 300:	old_space = 2; break;
		case 600:	old_space = 3; break;
		case 1200:	old_space = 4; break;
		case 2400:	old_space = 5; break;
	}

	return old_space*100;
}

//  简化过程，现在这个pay_time()的含义就是 last_pay_time了．
int pay_time()
{
	if (query("last_pay_time"))
		return query("last_pay_time");
	else
		return atoi(query("timestamp2"));
}

//	这个函数功能是把last_pay_time调节到离现在最近的那个过去的星期
int reset_pay_time()
{
	int n;
	n = (time()-pay_time())/DAY/7;
	set("last_pay_time", pay_time()+ n*DAY*7);
	return query("last_pay_time");
}

int balance_g(){		// unit = silver
	
	int left;
	left = query("total_gold")*100 - query("already_pay");
	
	if (left<=0 )
		return 0;
	else
		return left;	
}


int balance_s(){
	
	int left_s;
	left_s = query("total_score") -query("already_spay");
	
	if (left_s <=0)
		return 0;
	else
		return left_s;
	
}

/*
int do_pay()
{
	int t,s,n;
	int g;
	int gold;
	object me = this_player();
	if(!is_owner(me->query("id")))
		return 0;
	if (query("charged"))
		return notify_fail("你已经预付过下一次的月费了。\n");

	t = query_tax();
	s = query_stax();
	
	if (query("basic_tax") == -1)
		return notify_fail("你的屋子已经交清存款了。\n");
	
	gold  = this_player()->query("deposit")/100;
	if(gold < t)
       	return notify_fail("你在南宫家没有存够"+chinese_number(t)+"两银子。\n");
	
	if(me->query("score") < s/100)
       	return notify_fail("你的评价不足"+chinese_number(s/100)+"点！\n");
       	
	me->add("deposit",-t*100);
	me->add("score",-s/100);
	add("already_pay",t);
	add("already_spay",s/100);
	set("charged",1);
	
	if( !balance_s() && !balance_g()) {
		set("basic_tax",-1);
		log_file("annie_log_buildroom", 
			sprintf("Payoff: [%s] %s(%s)的自建房屋%s已经付清款项，档名为%s。\n",
			ctime(time()), 
			me->query("name"),
			me->query("id"),
			query("short"),
			base_name(this_object())));
		tell_object(me,"恭喜，你的屋子已经付清贷款，你拥有完全的主权了！！\n");
		save();
		return 1;
	}
		
	save();
    return notify_fail("你成功交纳了下一次的征赋（" + t + "两银子）！\n");
}
*/

int do_exercise(string arg)
{
	int t,s;
	int g;
	int gold, duration;
	object me = this_player();
	object contract;
	
	if(!is_owner(me->query("id")))
		return notify_fail ("这么大的事儿，要主人才能作主。\n");
	
	duration = query_temp("fight_switch")+ 3600 - time();
	if (duration >0)
		return notify_fail("改变房屋打斗属性每小时最多一次（"+ (duration/60)+"）\n");	
	
	if (arg == "1") {
		set("no_fight",0);
		set("no_magic",0);
		message_vision(HIR"该房间设定为可打斗空间。\n"NOR,me);
		message_vision(HIR"该房间设定为可使用法术空间。\n"NOR,me);
		set_temp("fight_switch",time());
		return 1;
	}
	
	if (arg == "0") {
		set("no_fight",1);
		set("no_magic",1);
		message_vision(HIG"该房间设定为不可打斗空间。\n"NOR,me);
		message_vision(HIG"该房间设定为不可使用法术空间。\n"NOR,me);
		set_temp("fight_switch",time());
		return 1;
	}
		
	return notify_fail("参数只能是１（允许打斗）或０（不允许打斗）\n");
}	
		
int do_payoff()
{
	int t,s;
	int g;
	int gold;
	object me = this_player();
	object contract;
	
	if(!is_owner(me->query("id")))
		return notify_fail ("想替别人付钱啊？\n");
		
	t = query_tax();
	s = query_stax();
	
	if (query("basic_tax") == -1)
		return notify_fail("你的屋子已经交清存款了。\n");
	
	if (!objectp(contract = present("payoff contract",me)))
		return notify_fail("为防止误操作，请先去购买一份合约（payoff contract）\n");
			
	t = balance_g();
	s = balance_s();

	if (!t && !s)
		return notify_fail("你的屋子已经交清存款了。\n");
		
	gold  = this_player()->query("deposit")/100;
	if(gold < t)
       	return notify_fail("你在南宫家没有存够"+chinese_number(t)+"两银子。\n");
	
	if(me->query("score") < s)
       	return notify_fail("你的评价不足"+chinese_number(s)+"点！\n");
       	
	me->add("deposit",-t*100);
	me->add("score",-s);
	
	tell_object(me,"你付出了" + t +"两白银，"+ s + "点评价。\n");
	
	add("already_pay",t);
	add("already_spay",s);
	set("charged",1);
	
	if( !balance_s() && !balance_g()) {
		set("basic_tax",-1);
		log_file("annie_log_buildroom", 
			sprintf("Payoff: [%s] %s(%s)的自建房屋%s已经付清款项，档名为%s。\n",
			ctime(time()), 
			me->query("name"),
			me->query("id"),
			query("short"),
			base_name(this_object())));
		destruct(contract);
		tell_object(me,"恭喜，你的屋子已经付清贷款，你拥有完全的主权了！！\n");
	}
		
	save();
	return 1;
	
}


int do_remodel(string arg){
	
	int old_space, new_space, num;
	int g, s, g1,g2,s1,s2,gold,level;
	object env,contract;
	object me = this_player();
	string this_room, my_file;
	
	g1 = query("total_gold");
	s1 = query("total_score");
	
	switch (g1) {
		case 150:	old_space = 1; break;
		case 300:	old_space = 2; break;
		case 600:	old_space = 3; break;
		case 1200:	old_space = 4; break;
		case 2400:	old_space = 5; break;
	}
	
	if(!is_owner(me->query("id")))
		return notify_fail ("这事儿只有主人才能做决定。\n");
	
	if (query("basic_tax") != -1)
		return notify_fail("先把这间屋子的贷款交清再说吧。\n");
	
	if (!objectp(contract = present("remodel contract",me)))
		return notify_fail("为防止误操作，请先去购买一份合约（remodel contract）\n");
		
	if (old_space>=5)
		return notify_fail("你的屋子已经具有最大空间了。\n");
		
	if (!arg || sscanf(arg,"%d",new_space)!=1)
		return notify_fail("格式：remodel 数字，数字为你想扩建到的空间。\n");
		
	if ( new_space <= old_space || new_space >5)
		return notify_fail("Remodel后的数字必须比你现有空间（"+old_space+"）大，比６小。\n");	 
		
	switch (new_space){
		case 1:		g2 = 150; s2 = 120; break;
		case 2: 	g2 = 300; s2 = 240; break;
		case 3:		g2 = 600; s2 = 380; break;
		case 4: 	g2 = 1200;s2 = 560; break;
		case 5:		g2 = 2400;s2 = 820; break;
		default:	tell_object(me,"房屋更新失败，请立即通知巫师，失败代码Room_0017\n");return 1;
	}

	g = g2 -g1;
	s = s2 -s1;
	
//	write ("remodel needs " + g + " gold, "+ s + " score \n");
	
	gold  = this_player()->query("deposit")/10000;
	if(gold < g)
       	return notify_fail("你在南宫家没有存够"+chinese_number(g)+"两金子。\n");

	if(me->query("score") < s)
       	return notify_fail("你的评价不足"+chinese_number(s)+"点！\n");
	
	env = this_object();
	log_file("annie_log_buildroom", 
			sprintf("Payoff: [%s] %s(%s)的自建房屋%s已经从%d改建到%d，档名为%s。\n",
			ctime(time()), 
			me->query("name"),
			me->query("id"),
			env->query("short"),
			old_space,
			new_space,
			base_name(env)));
	
	env->set("total_gold",g2);
	env->set("total_score",s2);
	env->set("free_space",new_space-(old_space-env->query("free_space")));
	env->save();
	
	me->add("deposit",-g*10000);
	me->add("score",-s);
		tell_object(me,"你付出了" + g +"两黄金，"+ s + "点评价。\n");
	me->save();
	destruct(contract);
	write("房屋改建成功！！改建人资料存储成功！！\n");
	return 1;

}	

/*
	房屋的参数:
	
	A类：在ROOM init时由文件自动从#define中设置	
		total_gold		:　 总额 ( gold)
		total_score		: 　总评价	
		room_flag		：　进入flag
		owner			:   屋主
		class			：　主人门派
		timestamp		:   第几间房
	B类：作为dbase的形式储存在玩家的数据目录下	
		already_pay		: 累计付款（silver）
		already_spay	: 累计评价
		basic_tax		：现在只作为是否付清所有款项的一个Ｍａｒｋ

*/


int do_here(string arg)
{
	string strx;
	write("\n╭════════════════════════════╮\n");
	strx = 
    strx="　　　　　　　　　　　"+WHT+query("short")+NOR"("+(query("outdoors")?CYN"室外":CYN"室内")+NOR")";
	strx=ngstr(strx+NOR,56);
	write("║"+strx+"║\n");
    strx="　建造於"+YEL+ "/cmds/usr/uptime"->chinese_time(7,""+query("timestamp2"))+NOR;
	strx=ngstr(strx+NOR,56);
	write("║"+strx+"║\n");
	write("║ ═══════════════════════════ ║ \n");
	strx = " ◆主人："CYN+query("owner")+NOR" ◆主人："CYN+(query("couple")?query("couple"):"无")+NOR" ◆借用者："CYN"特性关闭"NOR;
	strx=ngstr(strx+NOR,56);
	write("║"+strx+"║\n");
	write("║╭──────────────────────────╮║ \n");
	if (query("basic_tax") == -1)
	{
	write("║│　　　　　　　　　　　　　　　　　　　　　　　　　　│║ \n");
	write("║│　　　　　　　　　　　　　　　　　　　　　　　　　　│║ \n");
	write("║│　　　　　　　　　　　　　　　　　　　　　　　　　　│║ \n");
	write("║│　　　　　　　　　　　　　　　　　　　　　　　　　　│║ \n");
	strx="可用空间："CYN+query("free_space");
	strx=ngstr(strx+NOR,52);
	write("║│"+strx+"│║\n");
	}
	else
	{
	strx="银两征收："CYN+CHINESE_D->chinese_number(query_tax())+"两"NOR"/周 评价征收："CYN+CHINESE_D->chinese_number(query_stax()/100)+"点"NOR"/周";
	strx=ngstr(strx+NOR,52);
	write("║│"+strx+"│║\n");
	write("║│　　　　　　　　　　　　　　　　　　　　　　　　　　│║ \n");

	strx="上次缴纳："CYN+"/cmds/usr/uptime"->chinese_time(7,""+pay_time());
	strx=ngstr(strx+NOR,52);
	write("║│"+strx+"│║\n");
	
	strx="下次缴纳："CYN+"/cmds/usr/uptime"->chinese_time(7,""+(pay_time()+DAY*7));
	if (time()> pay_time()+ DAY*7)
		strx += HIR"（已欠款"+chinese_number(query("expired")/7+1)+"期）"NOR;
	
	strx=ngstr(strx+NOR,52);
	write("║│"+strx+"│║\n");
	
	write("║│　　　　　　　　　　　　　　　　　　　　　　　　　　│║ \n");
	strx="累计已交："CYN+query("already_pay")+"两"NOR"银子"CYN" "+query("already_spay")+"点"NOR"评价　　可用空间："CYN+query("free_space");
	strx=ngstr(strx+NOR,52);
	write("║│"+strx+"│║\n");
	}
	write("║╰──────────────────────────╯║\n");
	
	strx = "║ ◆房产总额："CYN + query("total_gold")+ NOR"两黄金"+"/"CYN+query("total_score")+NOR"点评价";
	strx = ngstr(strx +NOR,44);
	write( strx+"风云２００５  ║\n");
	
//	write("║ ◆当前税率："CYN"◎2.0%"NOR"　　　 　　　 　　　 　风云２００５　║\n");
	
	write("╰════════════════════════════╯\n");

	return 1;

}

int valid_enter(object me)
{
	int flag;
	int g, n;
			int t,s;
	int gold;
	string wiz_status;
// means no enter at the beginning.
	int enter = 0;
        flag = (int) query("room_flag");
// always let owner go in:
	if(is_owner(me->query("id")))
		enter = 1;
//  if(flag & 16)
//		enter = 1;
	if(flag & 32)	
		enter = 1;	
	if(query_temp("invite/"+me->query("id")))
		enter = 1;
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status == "(admin)"  )
	       enter = 1;
      
//  Upkeep cost already payed?
    

	if (query("expired") && query("basic_tax") != -1)
	{
		// 在这里写追缴函式
		enter = 0;
		if(is_owner(me->query("id")))
		{
			n = query("expired")/7 + 1;		// 欠多少周交多少
			t = query_tax()*n;
			s = query_stax()*n;
			tell_object(me,WHT"你在"+ chinese_number(n)+"周内未交维持费用。\n"NOR);
			
			if (query("expired")> 7) {
				tell_object(me,WHT"系统一次最多只征收两周的维持费用，欢迎回到游戏！\n"NOR);
				t = query_tax()*2;
				s = query_stax()*2;
			}
						
			gold  = this_player()->query("deposit")/100;					
			if(gold < t)
			{
				tell_object(me,"（你在南宫家没有存够"+chinese_number(t)+"两银子。）\n");
				return 0;
			}
			
			if(me->query("score") < s/100)
			{
				tell_object(me,"（你的评价不足"+chinese_number(s/100)+"点！）\n");
				return 0;
			}
			me->add("deposit",-t*100);
			me->add("score",-s/100);
			tell_object(me,YEL"你补交了所欠的维持费用（"+t+"两银子、"+(s/100)+"点评价）。\n"NOR);
			add("already_pay",t);
			add("already_spay",s/100);
			set("expired",0);
			set("charged",1);		// 在算 expired时候，是计算到下一周的，也就是说，这儿付的包括下一个。
			reset_pay_time();

			if( !balance_s() && !balance_g()) {
				set("basic_tax",-1);
				log_file("annie_log_buildroom", 
					sprintf("Payoff: [%s] %s(%s)的自建房屋%s已经付清款项，档名为%s。\n",
					ctime(time()), 
					me->query("name"),
					me->query("id"),
					query("short"),
					base_name(this_object())));
				tell_object(me,HIR"恭喜，你的屋子已经付清贷款，你拥有完全的主权了！！\n"NOR);
			}

			save();
			enter = 1;
		}
	}
	if(enter){
	set("room_last_enter",time());
	}

	if (!enter && query("expired") && query("basic_tax")!=-1)
		tell_object(me,"该房屋欠款未请，暂时无法进入！\n");
		
	return enter;
}

int do_invite(string arg)
{
	object me;
	mapping invite_list;
	int i;
	string *lists;
	me= this_player();
	if(!is_owner(me->query("id")))
		return 0;
	
	invite_list = query_temp("invite");
	
	if (arg) {
		if (mapp(invite_list))
			lists = keys(invite_list);
		if (lists && sizeof(lists))
		if (member_array(arg,lists)!= -1){
			delete_temp("invite/"+arg);
			write("你把"+arg+"从客人名单上删去了。\n");
			return 1;
		}
		set_temp("invite/"+arg,1);
		write("你邀请"+arg+"来你的房间。\n");
		return 1;
	}
	
	invite_list = query_temp("invite");
	
	write(WHT"\t　　邀请名单：\n"NOR);
	write(HIR BLK"────────────────\n"NOR);
	if( !mapp(invite_list) || !sizeof(invite_list) )
	{
		write("没有邀请任何人。\n");
		write(HIR BLK"────────────────\n"NOR);
		return 1;
	}
	lists = keys(invite_list);
	for(i=0; i<sizeof(lists); i++)
		write(lists[i]+"\n");
	write(HIR BLK"────────────────\n"NOR);
	return 1;
}

int do_setowner(string arg)
{
	string oldowner;
	if (!wizardp(this_player()) && !is_owner(this_player()->query("id")))
		return 0;
	oldowner = (string)query("temp_owner");
	set("temp_owner",arg);
	write("你将房间的主人暂时设为"+arg+"。\n");
	call_out("set_back",60, oldowner);
	return 1;
}

int do_share(string arg)
{
	object me;
	
	me= this_player();
	if((string)me->query("id") != query("owner"))
		return 0;
	if (!me->query("marry") )
		return notify_fail("你只能与你的另一半分享房间。\n");
	if (!arg)
		return notify_fail("设置指令为：share <id>。\n");
	if (arg != me->query("marry"))
		return notify_fail("你只能与你的另一半分享房间。\n");
	if (arg == query("owner"))
		return notify_fail("将自己设置为第二个主人？好主意．．．\n");
	if (query("couple"))
		return notify_fail("你只能设置一次房间的第二主人！\n");
	if (!find_player(arg))
		return notify_fail("第二主人必须在其在线时设置。\n");
	set("couple",arg);
	write("你添加了房间的第二主人："+arg+"。\n");
	tell_object(find_player(arg),me->query("name")+"将你设置为"+query("short")+"房间的第二主人。\n");
	return 1;
}

int set_back(string oldowner)
{
	set("temp_owner", oldowner);
	return 1;
}


string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id+".room"+query("timestamp")+".o");
}

int save()
{
        string file;
        int result;
		seteuid(query("owner"));
        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                return result;
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file))
                return 1;
        return 0;
}

int restore_item()
{
	object box,item;
	mapping item_list;
	string *lists,mitem;
	int i,idx;
/*
	box = new("/obj/item/box");
	box->move(this_object());

	item_list = query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return 1;
	// 没有任何东西。

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = query("item_list/"+lists[i]);
		item = new(mitem["item_basename"]);
		annie_itemmimic(item,mitem["data"],mitem["temp_data"]);
		item->set_name(mitem["item_name"],mitem["item_id"]);
		item->set_amount(mitem["amount"]);
		item->move(box);
	}
*/
	item_list = query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return 1;
	// 没有任何东西。

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = query("item_list/"+lists[i]);
		item = new(mitem);
		item->move(this_object());
		item->set("no_reset",1);
		item->restore_item();
	}
	return 1;
}

void reset()
{
	object *inv;
	int i;
	::reset();

	inv = all_inventory(this_object());
	for (i=0;i<sizeof(inv) ;i++ )
	{
		if (!inv[i]->query("item_type"))	continue;
		inv[i]->reset_item_list(inv[i]);	// save
	}
	return ;
}


int check_legal_long(string name)
{
        int i;
        i = sizeof(name);
        if( (sizeof(name) < 60) || (sizeof(name) > 300 ) ) {
                write("对不起，中文描述必须是六十到三百个中文字。"+sizeof(name)+"\n");
                return 0;
        }
        while(i--) {
		if(name[i]==' ' || name[i] == '\n') continue;
                if( name[i]<' ' ) {
                        write("对不起，中文描述不能用控制字元。\n");
                        return 0;
                }
                if( !is_chinese(name[i..<0]) ) {
                        write("对不起，描述必需是中文。\n");
                        return 0;
                }
        }
        return 1;
}

int enter_desc(object me, object room, string text){

	if(!check_legal_long(text)) return 1;
	
	if (me->query("deposit")< 50000) {
		tell_object(me, "你的银行存款不够，至少需要五两黄金。\n");
		return 1;
	}
	me->add("deposit",-50000);
	
	room->set("long", text);
	room->add("renovation",1);
	room->set("renovation_time",time());
	room->save();
	me->save();
	write("房屋描述修改成功！！！\n");
	return 1;
}


int input_description(){
	object me, env;
	me = this_player();
	
	if(!is_owner(me->query("id")))
		return notify_fail ("这事儿只有主人才能做决定。\n");
		
	env = environment(me);
	if (env->query("renovation_time")+ 600> time())
		return notify_fail("装修屋子的间隔时间不能少于十分钟。\n");
		
	if (me->query("deposit")< 50000)
		return notify_fail("你的银行存款不够，至少需要五两黄金。\n");
		
	me->edit( (: enter_desc , me, env :) );
	return 1;
}




/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
