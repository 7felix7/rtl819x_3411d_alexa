# RTL819X Platform Support
snd-soc-rtl819x-objs := rtl819x-pcm.o
snd-soc-rtl8197d-i2s-objs := rtl8197d-i2s.o
snd-soc-rtl819x-gpio-objs := rtl819x_gpio.o
snd-soc-rtl819x-i2c-objs := rtl819x_i2c.o
snd-soc-rtl819x-codec-i2c-objs := rtl819x_codec_i2c.o
snd-soc-i2c-rt5621-objs := i2c_rt5651.o
snd-soc-i2c-rt5659-objs := i2c_rt5659.o


obj-$(CONFIG_SND_RTL819XD_SOC_I2S) += snd-soc-rtl819x-gpio.o audio_event.o
ifeq ($(CONFIG_AUDIO_SINK_SUPPORT),y)
	#obj-$(CONFIG_SND_RTL819XD_SOC_I2S) += wifi_audio.o
endif

ifneq ($(CONFIG_SND_RTL819XD_SOC_ALC5659),y)
ifneq ($(CONFIG_SND_RTL819XD_SOC_ALC5680),y)
obj-$(CONFIG_SND_RTL819XD_SOC_I2S) += snd-soc-rtl819x-i2c.o
endif
endif



ifeq ($(CONFIG_SND_RTL819XD_SOC_ALC5659),y)
obj-$(CONFIG_SND_RTL819XD_SOC_ALC5659) += snd-soc-rtl819x-codec-i2c.o
endif



obj-$(CONFIG_SND_RTL819XD_SOC_ALC5651) += snd-soc-i2c-rt5651.o
obj-$(CONFIG_SND_RTL819XD_SOC_ALC5659) += snd-soc-i2c-rt5659.o

obj-$(CONFIG_SND_RTL819XD_SOC_I2S) += snd-soc-rtl819x.o
obj-$(CONFIG_SND_RTL819XD_SOC_I2S) += snd-soc-rtl8197d-i2s.o


# RTL819X Machine Support
snd-soc-rtl819xD-rt5628-objs := rtl819xD_rt5628.o
snd-soc-rtl819xD-rt5642-objs := rtl819xD_rt5642.o
snd-soc-rtl819xD-rt5633-objs := rtl819xD_rt5633.o
snd-soc-rtl819xD-rt5670-objs := rtl819xD_rt5670.o
snd-soc-rtl819xD-rt5651-objs := rtl819xD_rt5651.o
snd-soc-rtl819xD-rt5621-objs := rtl819xD_rt5621.o
snd-soc-rtl819xD-rt5659-objs := rtl819xD_rt5659.o
snd-soc-rtl819xD-rt5680-objs := rtl819xD_rt5680.o

obj-$(CONFIG_SND_RTL819XD_SOC_ALC5628) += snd-soc-rtl819xD-rt5628.o
obj-$(CONFIG_SND_RTL819XD_SOC_ALC5642) += snd-soc-rtl819xD-rt5642.o
obj-$(CONFIG_SND_RTL819XD_SOC_ALC5633Q) += snd-soc-rtl819xD-rt5633.o
obj-$(CONFIG_SND_RTL819XD_SOC_ALC5670) += snd-soc-rtl819xD-rt5670.o
obj-$(CONFIG_SND_RTL819XD_SOC_ALC5651) += snd-soc-rtl819xD-rt5651.o
obj-$(CONFIG_SND_RTL819XD_SOC_ALC5621) += snd-soc-rtl819xD-rt5621.o
obj-$(CONFIG_SND_RTL819XD_SOC_ALC5659) += snd-soc-rtl819xD-rt5659.o
obj-$(CONFIG_SND_RTL819XD_SOC_ALC5680) += snd-soc-rtl819xD-rt5680.o

