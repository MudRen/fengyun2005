//自然景观控制发生器
//sceneryd.c
//控制自然景观发生

#define TIME_TICK (time())
#define CALL_OUT_TIME 720
#define RATE 100

#include <ansi.h>

inherit F_DBASE;
mapping *scenery_phase;
int date;
int get_date();
int is_newday();
void add_date();
void update_scenery_phase();
void scenery_happen(mapping scenery);
void init_scenery_phase();
int show_scenery_phase();
mapping *read_table(string file);

void create()
{
        seteuid(getuid());
        scenery_phase=read_table("/adm/etc/scenery_phase");
        set("channel_id", "景观精灵");
        set("id","sceneryd");
        init_scenery_phase();
}

void init_scenery_phase()
{
        int i;
        date=NATURE_D->get_current_time()[2];
        for(i=0;i<sizeof(scenery_phase);i++)
        {
                scenery_phase[i]["happen"]=0;
                if(!stringp(catch(call_other(scenery_phase[i]["file"],"???"))))
                {
  			CHANNEL_D->do_sys_channel(
			"sys", sprintf("%s(%s)景观现在准备好了。mapping是%O\n",
	                scenery_phase[i]["name"],scenery_phase[i]["file"],scenery_phase[i]));

	         }
                else
                {
                        CHANNEL_D->do_sys_channel(
                        "sys",sprintf("%s(%s)景观可能有问题，请尽快检查。\n",
                        scenery_phase[i]["name"],scenery_phase[i]["file"]));
                }
        }
        call_out("update_scenery_phase",1);
}


void update_scenery_phase()
{
        int daytime,day;
        int i/*,success*/;
//      int season;
        int begintime,time;
        remove_call_out("update_scenery_phase");
        CHANNEL_D->do_sys_channel(
           "sys","开始处理scenery_phase");
        CHANNEL_D->do_sys_channel(
           "sys",sprintf("当前天是%d,上次处理的日期是%d，现在是否是newday?%d",NATURE_D->get_current_time()[2],get_date(),is_newday()));
        if(is_newday())
        {


		date=NATURE_D->get_current_time()[2];
        	daytime=NATURE_D->get_current_time()[5];
        	for(i=0;i<sizeof(scenery_phase);i++)
        	{
// here need rewrite
	                if(scenery_phase[i][sprintf("%d",NATURE_D->get_season())]==1)//季节对头了
        	        {
                		day=NATURE_D->get_current_time()[2];
                		begintime=0;
				if(scenery_phase[i]["end"]<0) begintime=1440+scenery_phase[i]["end"];
//			现在我们采取这种处理方法
//			首先，我们按照一天，也就是24分钟作为一次call_out的间隔
//			其次，我们会判断在这天内，目前现在的时间是否跟允许发生的时间相吻合
//			然后判断概率
//			当这些都满足以后，那么就要发生了
//			建议是把这些概率调低
//			ok,let's do it
				if(begintime)//在俩区间内
				{
//如果是可以发生的时间是两段时间的话，首先我们来判断一下目前的时间在哪个时间段之内，目前存在三个时间段，两个是可以发生的，一个是不可以发生的
					if(daytime<scenery_phase[i]["begin"])//目前时间是在第一段里面，那么随机挑选两段时间中的一个
					{
						if(random(2))//挑选第一段时间
							time=random(scenery_phase[i]["begin"]);
						else
							time=begintime+random(1440-begintime);
					}
					else // ok，实际上只要时间出了第一段，那么我们只能挑选第二段了
					{
						time=begintime+random(1440-begintime);
					}
				}
				else//在一个区间内
				{
//				if(scenery_phase[i]["begin"]<daytime
//		                && scenery_phase[i]["end"]>daytime)
				//这个time是从一天开始算起来，随机在这个区间里面挑选一个时间段进行，当然目前的daytime也得计算在内，在后面call_out的时候使用
					time=scenery_phase[i]["begin"]+random(scenery_phase[i]["end"]-scenery_phase[i]["begin"]);
		        	}
                       		if(random(RATE)<scenery_phase[i]["rate"])//概率满足了
                              	{
                                               	scenery_phase[i]["happen"]=1;//我们认为它要发生了
                                               	call_out("scenery_happen",time-daytime,scenery_phase[i]);
                               	}
                        //哦，这里有个小小的失误，开始写的时候没考虑到有两段时间发生
                        //那么我们将引入一个天的变量
                	}
		}

	}
//	cot=CALL_OUT_TIME+random(CALL_OUT_TIME);
//      call_out("update_scenery_phase",cot);
	call_out("update_scenery_phase",CALL_OUT_TIME+random(CALL_OUT_TIME));
}

//这个函数是判断是否可以自然景观的
void scenery_happen(mapping scenery)
{
        object room;
        if(!objectp(room=find_object(scenery["file"])))
                room=load_object(scenery["file"]);
        CHANNEL_D->do_sys_channel("sys",
                   sprintf("%s(%s)景观现在就要发生了，现在happen是%d。\n",
	           scenery["name"],scenery["file"],scenery["happen"]));
        room->init_scenery();
}

int show_scenery_phase()
{
	int i;
	for(i=0;i<sizeof(scenery_phase);i++)
        	write(sprintf("scenery_phase[%d] is %O\n",i,scenery_phase[i]));
        return 1;
}

mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;
//      write(sprintf("file is %s\n",file));
        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
//               write(sprintf("line[%d]= %O\n field=%O\n format= %O \n",i,line[i],field,format));
                if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
	                continue;
                }
                break;
        }
//      write(sprintf("line= %O\n field=%O\n format= %O \n",line,field,format));
        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}

int get_date()
{
	return date;
}

int is_newday()
{
 	return (get_date()!=NATURE_D->get_current_time()[2]);
}

void add_date()
{
	date++;
}