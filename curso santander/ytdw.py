from pytube import YouTube

def download_video(url, output_path="."):
    proxies = {
        "http": "http://your_proxy_here",
        "https": "https://your_proxy_here",
    }
    yt = YouTube(url, proxies=proxies)
    ys = yt.streams.get_highest_resolution()
    ys.download(output_path)
    print(f"Downloaded: {yt.title}")

if __name__ == "__main__":
    video_url = input("Enter the URL of the video you want to download: ")
    download_video(video_url)