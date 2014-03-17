from setuptools import setup

setup(
    name="weather",
    version="2.3",
    author="Jeremy Stanley",
    author_email="fungi@yuggoth.org",
    description="CLI tool which shows weather forecasts from METAR data",
    license="BSD2",
    url="http://fungi.yuggoth.org/weather/",
    keywords="weather",
    py_modules=["weather"],
    scripts=["weather"],
    data_files=[
        ("/etc", ["weatherrc"]),
        ("share/man/man1", ["weather.1"]),
        ("share/man/man5", ["weatherrc.5"]),
        ("share/weather", ["airports", "overrides.conf", "places", "slist",
                           "stations", "zctas", "zlist", "zones"]),
        ("share/licenses/weather", ["LICENSE"])]
)
