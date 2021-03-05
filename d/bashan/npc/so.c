#include <ansi.h>
inherit NPC;
int lotto();
int listx();
int start=0;

string *lottoo=({"朝廷","丐帮","金钱帮","少林寺","大昭寺","兴国寺","武当","华山","狼山","帝王谷","快活林","白云城","魔教","天枫十四","三清宫","神水宫","皓月宫","万梅山庄","铁雪山庄","神剑山庄","富贵山庄","落花神殿",});

void create()
{
    set_name("素馨", ({"su"}) );
    set("gender", "女性" );
    set("attitude", "friendly");
    set("age",32);
    set("NO_KILL",1);

    setup();
}

int do_look(string arg)
{
    if (!arg)
	return 0;
    if (present(arg,environment()) != this_object())
	return 0;
    write(CYN"
素馨微笑道：现在是乐透开彩第"+(ANNIE_D->lotto_get_roll_round()+1)+"期。
素馨微笑道：上一期"+ANNIE_D->lotto_get_roll_result()+"。\n\n"NOR);
	write(CYN"素馨微笑道：在这里你可以使用以下指令：
lottolist 查询你已经购买的彩券
purchase <数目>一次支付一笔钱，让我为你乱数抽取一些彩券
checkout 结算上一期的彩金\n\n"NOR);
	write("她看起来约十多岁。
她"HIG"柔媚娇艳，浑身上下散发着无穷的诱惑。"NOR"
她"CYN"体态轻盈"NOR"，武功看起来好象"BLU"初学乍练"NOR"，出手似乎极轻。
她"HIG"看来身上并无丝毫伤痕。"NOR"
她身穿倾国霓裳(Cloth)。\n");
	return 1;
}

int checkout()
{
	object me = this_player();
	mapping data;
	int i,j;
	int r1,r2,r3,r4,r5;

	int l1=1000,l2=200,l3=50,l4=20,l5=5;

/*
// L2不给gold了。-- 这些。。不算一等阿
	string *l2_reward = ({
"/obj/specials/annie/seal",
"/obj/specials/annie/peach",
"/obj/specials/annie/magicfan",
"/obj/specials/annie/evileye",
	}) ;
*/
	int b;

	string arg;
	object obj;

	if (time()-query("last_work") < 2)
		return notify_fail(CYN"素馨微笑道：馨儿正在busy中，客官请稍待片刻。\n"NOR);
	set("last_work",time());

	if (ANNIE_D->lotto_get_roll_round() == me->query("lotto_roll"))
		return notify_fail(CYN"素馨微笑道：这位客官，你已经兑换过本期的彩券了。\n"NOR);
	me->set("lotto_roll",ANNIE_D->lotto_get_roll_round());

	data=ANNIE_D->lotto_checkout(me->query("id"));
	r1=data["r1"];
	r2=data["r2"];
	r3=data["r3"];
	r4=data["r4"];
	r5=data["r5"];
	arg=CYN"你中了特等奖"+r1+"注，得到黄金"+r1*l1+"两，\n";
	arg += "一等奖"+r2+"注，得到黄金"+r2*l2+"两，\n";

/*	arg += "一等奖"+r2+"注，得到";
	if (r2 == 0)
		arg += "黄金0两";
	else
	for (i=0;i<r2 ;i++ )
	{
		obj = new(l2_reward[random(sizeof(l2_reward))]);
		obj->move(me);
		arg += obj->name()+CYN"一"+obj->query("unit");
		if (i < r2-1)
			arg += "、";
	}
	arg += "，\n";*/
	arg += "二等奖"+r3+"注，得到黄金"+r3*l3+"两，\n三等奖"+r4+"注，得到黄金"+r4*l4+"两，\n安慰奖"+r5+"注，得到黄金"+r5*l5+"两，";
	b=r1*l1+r2*l2+r3*l3+r4*l4+r5*l5;
	arg += "共计黄金"+chinese_number(b)+"两！\n\n"NOR;
	ANNIE_D->lotto_pay_money(b);
	tell_object(me,arg);
	me->add("deposit",b*10000);
	// timer: 每个count只能执行一次(资源占用大户)
	return 1;
}

int listx()
{
	object me = this_player();
	mapping data;
	mapping player_data;
	int i,left;
	string outp;
	string *mterm;
	int nnr;

	if (time()-query("last_work") < 2) {
		tell_object(CYN"素馨正忙，请稍待片刻。\n"NOR);
		return 1;
	}
	set("last_work",time());


	left = find_call_out("do_process");
	if (left>0)
		tell_object(me,"素馨说：每三小时开奖一次，距下次还有"+ chinese_number(left/60)+"分钟。\n");
	
	data = ANNIE_D->lotto_getlist(me->query("id"));
   	set_eval_limit(1); 
	if(!mapp(data) || !sizeof(data))
	{
		tell_object(me,"你没有购买任何的乐透彩券。\n");
		return 1;
	}
	else
	{
		tell_object(me,CYN"你购买的乐透彩券有：\n"NOR);

		mterm = keys(data);
		nnr=sizeof(mterm);
		if (nnr>20)
			nnr=20;

		for(i=0;i<nnr;i++)
		{
	    	reset_eval_cost();
			outp=data[mterm[i]];
			player_data=ANNIE_D->lotto_get_player_data(outp);
			
			tell_object(me,sprintf(HIR BLK"第"HIY"%d"NOR HIR BLK"期，"NOR WHT"%s－%s－%s－%s－%s\n"NOR,player_data["round"],lottoo[player_data["num1"]-1],lottoo[player_data["num2"]-1],lottoo[player_data["num3"]-1],lottoo[player_data["num4"]-1],lottoo[player_data["num5"]-1]));
		}       
		if (nnr == 20)
			tell_object(me,"你所购彩券太多，未能一览而尽。\n");

		return 1;
	}
}

int lotto()
{
	object me = this_player();
	string file;
	if (me->query("deposit") < 10000)
	{
		tell_object(me,CYN"素馨微笑道：请确认你在南宫家有足够存款，每注一两黄金。\n"NOR);
		return 1;
	}
	write(CLR);
	file = "/doc/lotto";
	write(read_file(file));
	me->delete_temp("lotto");
	tell_object(me,"请选择第一个门派：");
	input_to("selete_main",me,file,1);
	me->add_temp("block_msg/all",1);
	return 1;
}

int buyx(string arg)
{
	object me = this_player();
	string file;
	int amount,range=22,i;
	int i1,i2,i3,i4,i5;

	if (time()-query("last_work") < 2){
		tell_object(me,CYN"素馨正在忙呢，请稍待片刻。\n"NOR);
		return 1;
	}
	
	set("last_work",time());
	if (!arg){
		tell_object(me,"请输入你决定买多少笔彩券。\n");
		return 1;
	}
	
	amount=atoi(arg);
	if (amount + "" != arg){
		tell_object(me,"请输入你决定买多少笔彩券。\n");
		return 1;
	}
	
	if (amount < 0) {
		tell_object(me,"负数？你想中的也是负数？\n");
		return 1;
	}
		
	if (amount > 100) {
		tell_object(me,"你一次最多只能购买一百笔。\n");
		return 1;
	}
	
	if (me->query("deposit") < amount*10000)
	{
		tell_object(me,CYN"素馨微笑道：请确认你在南宫家有足够存款，每注一两黄金。\n"NOR);
		return 1;
	}
	
   	set_eval_limit(1); 
	for (i=0; i<amount; i++)
	{
    	reset_eval_cost();
		i1=random(range)+1;
		i2 = random(range)+1;
		i3 = random(range)+1;
		i4 = random(range)+1;
		i5 = random(range)+1;
		while (i1 == i2)
			i2 = random(range)+1;
		while (i1 == i3 || i2 == i3)
			i3 = random(range)+1;
		while (i1 == i4 || i2 == i4 || i3 == i4)
			i4 = random(range)+1;
		while (i1 == i5 || i2 == i5 || i3 == i5 || i4 == i5)
			i5 = random(range)+1;
		arg=i1+"-"+i2+"-"+i3+"-"+i4+"-"+i5;
		ANNIE_D->lotto_swarm_add(this_player(),arg);
	}
	ANNIE_D->lotto_prog();
	me->add("deposit",-amount*10000);
	tell_object(me,CYN"素馨微笑道：你已经购买了"+chinese_number(amount)+"注彩券，请用lottolist指令查看。\n"NOR);
	return 1;
}

void sel(object me)
{
	int i,j,flag=0;
	string msg;
	string arg="";
	for (i=1;i<=5 ; i++)
		for (j=i+1;j<=5 ;j++ )
			if (me->query_temp("lotto/"+i) == me->query_temp("lotto/"+j))
				flag=1;
	if (flag == 1)
	{
		tell_object(me,HIW"不能多次选择相同的门派！\n"NOR);
		return;
	}
	if (me->query("deposit") < 10000)
	{
		tell_object(me,CYN"素馨微笑道：请确认你在南宫家有足够存款，每注一两黄金。\n"NOR);
		return ;
	}
	me->add("deposit",-10000);
	for (i=1;i<5 ; i++)
		arg+=me->query_temp("lotto/"+i)+"-";
	arg += me->query_temp("lotto/5");
	msg=WHT"你买下一张写着“"HIM;
	for (i=1;i<5 ; i++)
		msg+=lottoo[atoi(me->query_temp("lotto/"+i))-1]+NOR WHT"、"HIM;
	msg += lottoo[atoi(me->query_temp("lotto/5"))-1]+NOR WHT"”的乐透彩券。\n"NOR;
	tell_object(me,msg);
	ANNIE_D->lotto_add(this_player(),arg);
	return;
}
	
void selete_main (string num, object me, string file,int count)
{
	if (!num || atoi(num)<1 || atoi(num) > 22 || atoi(num)+"" != num)
	{
		input_to("selete_main",me,file,count);
		return ;
	}
	me->set_temp("lotto/"+count,num);
	count++;
	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
	if (count >= 6)
	{
		sel(me);
		return ;
	}
	tell_object(me,"请选择第"+chinese_number(count)+"个门派：");
	me->add_temp("block_msg/all",1);
	input_to("selete_main",me,file,count);
	return ;
}

int init()
{
	add_action("do_look","look");
//	add_action("do_bet","bet");
//	add_action("do_bett","bett");
	add_action("do_next","next");
//	add_action("lotto","choose");	--- BUGGED
	add_action("listx","lottolist");
	add_action("buyx","purchase");
	add_action("checkout","checkout");
	if (environment() && !start) {
		call_out("do_promote",10200,this_object());
		call_out("do_process",10800,this_object());
		start = 1;
	}	
}

int do_bet(string arg)
{
	ANNIE_D->lotto_add(this_player(),arg);
	write("Ok.\n");
	return 1;
}

int do_bett(string arg)
{
	int i;
   	set_eval_limit(1); 
	for (i=0; i<1000; i++)
	{
    	reset_eval_cost();
		this_player()->ccommand("bet 1-2-3-4-5");
		this_player()->ccommand("next");
	}
	return 1;
}

int do_promote(object ob){
	CHANNEL_D->do_channel(this_object(),"announce","风云彩券还有十分钟就要开奖了，欢迎大家踊跃购买。");
	call_out("do_promote", 10800, ob);
	return 1;
}

int do_process(object ob){
	
	ANNIE_D->lotto_roll(ob);
	call_out("do_process",10800,ob);	
	return 1;
}


int do_next()
{
	if (!wizardp(this_player()))	
		return 0;
	remove_call_out("do_process");
	do_process(this_object());	
	return 1;
}

/*
fengyun-
奁镜朱颜辞流水，年华不识花自飞……
dancing_faery@hotmail.com
annie.01.01.2004
*/

// update here;update /adm/daemons/annied;update /d/bashan/npc/so;clone;
